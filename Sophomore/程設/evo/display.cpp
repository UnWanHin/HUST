#include "definition.hpp"

//主菜單
void display(){
    int op0,op1,op4,way=1;
    bool *value = NULL;//存儲答案
    CNF cnf = (CNF)malloc(sizeof(cnfNode));
    cnf->root = NULL;
    char fileName[100];
    vector<int> NormalBoard(81, 0);//數獨完整棋盤
    vector<int> GameBoard(81, 0);//挖洞生成的數獨遊戲棋盤
    vector<int> GamePlayBoard(81, 0);//玩家填寫的數獨遊戲棋盤
    int empty = 0;//挖洞數目
    int x = 0, y = 0, num = 0;//玩家輸入的座標和數位

    srand(time(0));//亂數種子
    while(true){
        system("cls");
        cout << endl << endl;
        cout << "\t  菜  單" << endl;
        cout << "**********************************" << endl;
        cout << endl;
        cout << "1.SAT求解器\t  2.數獨遊戲"<< endl;
        cout << endl;
        cout << "0. Exit" << endl;
        cout << "**********************************" << endl;        
        cin >> op0;
        system("cls");
        switch(op0){
        case 0:
            return ;
        case 1:
            op1=1;
            while (op1){
                system("cls");
                cout << endl << endl;
                cout << "\t  SAT 求  解  菜  單" << endl;
                cout << "**********************************" << endl;
                cout << endl;
                cout << "1.讀取文件\t  2.輸出檔"<< endl;
                cout << endl;
                cout << "3.求解文件\t  0. 返回" << endl;
                cout << "**********************************" << endl;   
                cin >> op1;
                system("cls");
                switch (op1)
                {
                case 1:
                    if (cnf->root != NULL) // 如果已經打開了CNF檔
                    {
                        printf(" 檔已讀取，是否重新讀取\n");
                        printf(" 1.是\t  0.否\n");
                        int choice;
                        scanf("%d", &choice);
                        if (choice == 0)
                            break;
                        else // 重新讀取
                        {
                            destroyCNF(cnf); // 銷毀當前解析的CNF
                        }
                    }
                    printf("請輸入檔路徑: ");
                    scanf("%s", fileName);

                    cnf=readCNF(fileName);// 讀取文件並解析CNF
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    if (cnf->root == NULL) printf("未讀取文件！");
                    else printCNF(cnf);
                    system("pause");
                    break;
                case 3:
                    if (cnf->root == NULL) printf("未讀取文件！");
                    else{
                        system("cls");
                        cout << endl;
                        cout << "----------變元選擇策略------------" << endl;
                        cout << "**********************************" << endl;
                        cout << "---1.選擇第一個變元" << endl;                       
                        cout << "---2.選擇出現次數最多的文字" << endl;
                        cout << "---3.選擇最短子句中出現次數最多的文字" << endl;
                        cout << "---0.返回" << endl;
                        cout << "**********************************" << endl;
                        cout << "請輸入變元選擇策略:";    
                        scanf("%d",&way);             
                        if(way == 0) break;
                        else {
                            CNF newCnf = (CNF)malloc(sizeof(cnfNode));
                            newCnf->root = CopyCnf(cnf->root); // 複製CNF
                            newCnf->boolCount = cnf->boolCount;
                            newCnf->clauseCount = cnf->clauseCount;
                            value = (bool *)malloc(sizeof(bool) * (cnf->boolCount + 1));
                            for (int i = 1; i <= cnf->boolCount; i++)
                                value[i] = TRUE;   
                            LARGE_INTEGER frequency, frequency_;    // 計時器頻率
                            LARGE_INTEGER start, start_, end, end_; // 設置時間變數
                            double time, time_;
                            // 未優化的時間
                            QueryPerformanceFrequency(&frequency);
                            QueryPerformanceCounter(&start); // 計時開始;
                            int result = DPLL(newCnf, value, way);
                            QueryPerformanceCounter(&end);                                       // 結束
                            time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // 計算執行時間 
                            // 輸出SAT結果
                            if (result == OK) // SAT
                            {
                                printf(" 有解\n\n");
                                // 輸出文字的真值
                                for (int i = 1; i <= cnf->boolCount; i++)
                                {
                                    if (value[i] == TRUE)
                                        printf(" %-4d: TRUE\n", i);
                                    else
                                        printf(" %-4d: FALSE\n", i);
                                }
                            }
                            else // UNSAT
                                printf(" 無解\n");
                            // 輸出優化前的時間
                            printf("\n Time: %lf ms\n", time * 1000);
                            // 是否優化
                            int ch;
                            printf("\n 是否與策略3進行對比?\n");
                            printf(" 1.是\t  0.否\n");
                            scanf("%d", &ch);
                            if (ch == 0)
                                time_ = 0;
                            else
                            {
                                // 銷毀之前的 newCnf 和 value
                                destroyCNF(newCnf);
                                free(value);

                                // 重新分配 newCnf
                                newCnf = (CNF)malloc(sizeof(cnfNode));
                                newCnf->root = CopyCnf(cnf->root);
                                newCnf->boolCount = cnf->boolCount;
                                newCnf->clauseCount = cnf->clauseCount;

                                // 重新分配 value 陣列並初始化
                                value = (bool*)malloc(sizeof(bool) * (cnf->boolCount + 1));
                                for (int i = 1; i <= cnf->boolCount; i++)
                                    value[i] = TRUE;

                                // 重新計時策略3
                                QueryPerformanceFrequency(&frequency_);
                                QueryPerformanceCounter(&start_);
                                int result_ = DPLL(newCnf, value, 3);  // 使用策略3，這裡可以忽略result_或因需要處理
                                QueryPerformanceCounter(&end_);
                                time_ = (double)(end_.QuadPart - start_.QuadPart) / frequency_.QuadPart;
                                printf("\n Time: %lf ms\n", time_ * 1000);
                                
                                // 計算優化率（百分比），並確保分母不為零
                                if (time != 0.0) {
                                    double optimizationRate = (time - time_) / time * 100;
                                    printf("\n優化率： %lf%%\n", optimizationRate);
                                }
                            }
                            // 是否保存
                            printf("\n 是否保存運行結果？\n ");
                            printf(" 1.是\t  0.否\n");
                            int choice;
                            scanf("%d", &choice);
                            printf("\n");
                            if (choice == 1)
                            {
                                // 保存求解結果
                                if (SaveResult(result, time, time_, value, fileName, cnf->boolCount))
                                    printf(" 保存成功.\n");
                                else
                                    printf(" 保存失敗.\n");
                            }
                        }     
                    }
                    break;
                case 0:
                    break;
                }
            }
            break;
        case 2:
            system("cls");
            generateDiagonalSudoku(NormalBoard);
            empty = generateGameBoard(NormalBoard, GameBoard);
            GamePlayBoard = GameBoard;
            op4 = 1;
            while(op4){
                    system("cls");
                    cout << endl;
                    cout << "-----------------數獨遊戲-----------------" << endl << endl;
                    cout << "\t1.填寫數字     2.查看答案" << endl << endl;
                    cout << "\t3.重新開始     4.擦除數字" << endl << endl;
                    cout << "\t5.DPLL求解     0.返回" << endl;
                    cout << "-------------------------------------------" << endl << endl;    
                    PrintBoard(GamePlayBoard);
                    printf("請輸入操作：");
                    cin>>op4;     
                    switch (op4)
                    {
                    case 0:
                        system("cls");
                        break;
                    case 1:
                            cout << "請輸入座標（x,y）和數位：";
                            cin >> x >> y >> num;
                            if (x < 1 || x>9 || y < 1 || y>9 || num < 0 || num>9)
                            {
                                cout << "輸入錯誤，請重新輸入" << endl;
                                system("pause");
                                break;
                            }
                            
                            if (GameBoard[(x - 1) * 9 + y - 1] != 0)
                            {
                                cout << "該位置不可填寫，請重新輸入" << endl;
                                system("pause");
                                break;
                            }
                            //檢測當前局面是否合法
                            if (checkSafe(GamePlayBoard, x-1, y-1, num) == false)
                            {
                                cout << "填寫錯誤，請重新輸入" << endl;
                                system("pause");
                                break;
                            }

                            GamePlayBoard[(x - 1) * 9 + y - 1] = num;
                            cout << endl;
                            PrintBoard(GamePlayBoard);                 
                        break;
                    case 2:
                            cout << endl;
                            PrintBoard(NormalBoard);
                            system("pause");
                            break;
                    case 3:
                            GamePlayBoard = GameBoard;
                            system("cls");
                            PrintBoard(GamePlayBoard);
                            break;
                    case 4:
                            cout << "請輸入座標（x,y）";
                            cin>>x>>y;
                            if (x < 1 || x>9 || y < 1 || y>9 || num < 0 || num>9)
                            {
                                cout << "輸入錯誤，請重新輸入" << endl;
                                system("pause");
                                break;
                            }
                            if (GameBoard[(x - 1) * 9 + y - 1] != 0)
                            {
                                cout << "不可擦除題目中的數位，請重新輸入" << endl;
                                system("pause");
                                break;
                            }
                            GamePlayBoard[(x - 1) * 9 + y - 1] = 0;
                            system("pause");
                            break;
                    case 5:
                            if(shudutocnf(GameBoard,empty)){
                                CNF cnfshudu = (CNF)malloc(sizeof(cnfNode));
                                cnfshudu = readCNF("shudu.cnf");
                                system("cls");
                                cout << endl;
                                cout << "----------變元選擇策略------------" << endl;
                                cout << "**********************************" << endl;
                                cout << "---1.選擇第一個變元" << endl;                       
                                cout << "---2.選擇出現次數最多的文字" << endl;
                                cout << "---3.選擇最短子句中出現次數最多的文字" << endl;
                                cout << "---0.返回" << endl;
                                cout << "**********************************" << endl;
                                cout << "請輸入變元選擇策略:";    
                                scanf("%d",&way);             
                                if(way == 0) break;
                                else {
                                    CNF newCnf = (CNF)malloc(sizeof(cnfNode));
                                    newCnf->root = CopyCnf(cnfshudu->root); // 複製CNF
                                    newCnf->boolCount = cnfshudu->boolCount;
                                    newCnf->clauseCount = cnfshudu->clauseCount;
                                    value = (bool *)malloc(sizeof(bool) * (cnfshudu->boolCount + 1));
                                    for (int i = 1; i <= cnfshudu->boolCount; i++)
                                        value[i] = TRUE;   
                                    LARGE_INTEGER frequency, frequency_;    // 計時器頻率
                                    LARGE_INTEGER start, start_, end, end_; // 設置時間變數
                                    double time, time_;
                                    // 未優化的時間
                                    QueryPerformanceFrequency(&frequency);
                                    QueryPerformanceCounter(&start); // 計時開始;
                                    int result = DPLL(newCnf, value, way);
                                    QueryPerformanceCounter(&end);                                       // 結束
                                    time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // 計算執行時間 
                                    // 輸出SAT結果
                                    if (result == OK) // SAT
                                    {
                                        printf(" 有解\n\n");
                                        // 輸出文字的真值
                                        for (int i = 1; i <= newCnf->boolCount; i++)
                                        {
                                            if (value[i] == TRUE)
                                                printf(" %-4d: TRUE\n", i);
                                            else
                                                printf(" %-4d: FALSE\n", i);
                                        }
                                    }
                                    else // UNSAT
                                        printf(" 無解\n");
                                    printf("\n Time: %lf ms\n", time * 1000);
                                    system("pause");
                                }                                 
                            }
                            break;
                    default:
                        break;
                    }
            }
            break;
        }

    }
    if (cnf->root != NULL)
        destroyCNF(cnf); // 退出時銷毀CNF
    free(cnf);

    return ;
}



