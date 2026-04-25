#include "definition.hpp"

//主菜单
void display(){
    int op0,op1,op4,way=1;
    bool *value = NULL;//存储答案
    CNF cnf = (CNF)malloc(sizeof(cnfNode));
    cnf->root = NULL;
    char fileName[100];
    vector<int> NormalBoard(81, 0);//数独完整棋盘
    vector<int> GameBoard(81, 0);//挖洞生成的数独游戏棋盘
	vector<int> GamePlayBoard(81, 0);//玩家填写的数独游戏棋盘
	int empty = 0;//挖洞数目
	int x = 0, y = 0, num = 0;//玩家输入的坐标和数字

	srand(time(0));//随机数种子
    while(true){
        system("cls");
        cout << endl << endl;
        cout << "\t uneM 菜  單 Menu" << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
        cout << "1.SAT求解器\t  2.數獨遊戲"<< endl;
        cout << endl;
        cout << "0. Exit\n" << endl;
        cout << "----------------------------------" << endl;        
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
                cout << "------------------------------------" << endl;
                cout << endl;
                cout << "1.讀取文件\t  2.輸出文件"<< endl;
                cout << endl;
                cout << "3.求解文件\t  0. 返回\n" << endl;
                cout << "------------------------------------" << endl;   
                cin >> op1;
                system("cls");
                switch (op1)
                {
                case 1:
                    if (cnf->root != NULL) // 如果已经打开了CNF文件
                    {
                        printf(" 文件已讀取，是否重新讀取\n");
                        printf(" 1.是\t  0.否\n");
                        int choice;
                        scanf("%d", &choice);
                        if (choice == 0)
                            break;
                        else // 重新读取
                        {
                            destroyCNF(cnf); // 销毁当前解析的CNF
                        }
                    }
                    printf("請輸入文件路徑: ");
                    scanf("%s", fileName);

                    cnf=readCNF(fileName);// 读取文件并解析CNF
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
						cout << "----------變元選揀策略------------" << endl;
                        cout << "--------------------------------------\n" << endl;
                        cout << "---1.選擇第一個變元\n" << endl;                       
                        cout << "---2.選擇出現次數最多的文字\n" << endl;   
                        cout << "---3.選揀最短子句中出現次數最多的文字\n" << endl;
                        cout << "---0.返回\n" << endl;
                        cout << "--------------------------------------" << endl;
                        cout << "請輸入變元選擇策略:";    
                        scanf("%d",&way);             
                        if(way == 0) break;
                        else {
                            CNF newCnf = (CNF)malloc(sizeof(cnfNode));
                            newCnf->root = CopyCnf(cnf->root); // 复制CNF
                            newCnf->boolCount = cnf->boolCount;
                            newCnf->clauseCount = cnf->clauseCount;
                            value = (bool *)malloc(sizeof(bool) * (cnf->boolCount + 1));
                            for (int i = 1; i <= cnf->boolCount; i++)
                                value[i] = TRUE;   
                            LARGE_INTEGER frequency, frequency_;    // 计时器频率
                            LARGE_INTEGER start, start_, end, end_; // 设置时间变量
                            double time, time_;
                            // 未优化的时间
                            QueryPerformanceFrequency(&frequency);
                            QueryPerformanceCounter(&start); // 计时开始;
                            int result = DPLL(newCnf, value, way);
                            QueryPerformanceCounter(&end);                                       // 结束
                            time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // 计算运行时间 
                            // 输出SAT结果
                            if (result == OK) // SAT
                            {
                                printf(" 有解\n\n");
                                // 输出文字的真值
                                for (int i = 1; i <= cnf->boolCount; i++)
                                {
                                    if (value[i] == TRUE)
                                        printf(" %-4d: TRUE\n", i);
                                    else
                                        printf(" %-4d: FALSE\n", i);
                                }
                            }
                            else // UNSAT
                                printf(" 无解\n");
                            // 输出优化前的时间
                            printf("\n Time: %lf ms\n", time * 1000);
                            // 是否优化
                            int ch;
                            printf("\n 是否与策略3進行對比?\n");
                            printf(" 1.是\t  0.否\n");
                            scanf("%d", &ch);
                            if (ch == 0)
                                time_ = 0;
                            else
                            {
                                // 销毁之前的 newCnf 和 value
                                destroyCNF(newCnf);
                                free(value);

                                // 重新分配 newCnf
                                newCnf = (CNF)malloc(sizeof(cnfNode));
                                newCnf->root = CopyCnf(cnf->root);
                                newCnf->boolCount = cnf->boolCount;
                                newCnf->clauseCount = cnf->clauseCount;

                                // 重新分配 value 数组并初始化
                                value = (bool*)malloc(sizeof(bool) * (cnf->boolCount + 1));
                                for (int i = 1; i <= cnf->boolCount; i++)
                                    value[i] = TRUE;

                                // 重新计时策略3
                                QueryPerformanceFrequency(&frequency_);
                                QueryPerformanceCounter(&start_);
                                int result_ = DPLL(newCnf, value, 3);  // 使用策略3，这里可以忽略result_或因需要处理
                                QueryPerformanceCounter(&end_);
                                time_ = (double)(end_.QuadPart - start_.QuadPart) / frequency_.QuadPart;
                                printf("\n Time: %lf ms\n", time_ * 1000);
                                
                                // 计算优化率（百分比），并确保分母不为零
                                if (time != 0.0) {
                                    double optimizationRate = (time - time_) / time * 100;
                                    printf("\n优化率： %lf%%\n", optimizationRate);
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
                                // 保存求解结果
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
                    cout << "-----------------数独游戏-----------------" << endl << endl;
                    cout << "\t1.填写数字     2.查看答案" << endl << endl;
                    cout << "\t3.重新开始     4.擦除数字" << endl << endl;
                    cout << "\t5.DPLL求解     0.返回" << endl;
                    cout << "-------------------------------------------" << endl << endl;    
                    PrintBoard(GamePlayBoard);
                    printf("请输入操作：");
                    cin>>op4;     
                    switch (op4)
                    {
                    case 0:
                        system("cls");
                        break;
                    case 1:
							cout << "请输入坐标（x,y）和数字：";
							cin >> x >> y >> num;
							if (x < 1 || x>9 || y < 1 || y>9 || num < 0 || num>9)
							{
								cout << "输入错误，请重新输入" << endl;
								system("pause");
								break;
							}
							
							if (GameBoard[(x - 1) * 9 + y - 1] != 0)
							{
								cout << "该位置不可填写，请重新输入" << endl;
								system("pause");
								break;
							}
							//检测当前局面是否合法
							if (checkSafe(GamePlayBoard, x-1, y-1, num) == false)
							{
								cout << "填写错误，请重新输入" << endl;
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
                            cout << "请输入坐标（x,y）";
                            cin>>x>>y;
                            if (x < 1 || x>9 || y < 1 || y>9 || num < 0 || num>9)
							{
								cout << "输入错误，请重新输入" << endl;
								system("pause");
								break;
							}
                            if (GameBoard[(x - 1) * 9 + y - 1] != 0)
							{
								cout << "不可擦除题目中的数字，请重新输入" << endl;
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
                                cout << "----------变元选择策略------------" << endl;
                                cout << "**********************************" << endl;
                                cout << "---1.选择第一个变元" << endl;                       
                                cout << "---2.选择出现次数最多的文字" << endl;
                                cout << "---3.选择最短子句中出现次数最多的文字" << endl;
                                cout << "---0.返回" << endl;
                                cout << "**********************************" << endl;
                                cout << "请输入变元选择策略:";    
                                scanf("%d",&way);             
                                if(way == 0) break;
                                else {
                                    CNF newCnf = (CNF)malloc(sizeof(cnfNode));
                                    newCnf->root = CopyCnf(cnfshudu->root); // 复制CNF
                                    newCnf->boolCount = cnfshudu->boolCount;
                                    newCnf->clauseCount = cnfshudu->clauseCount;
                                    value = (bool *)malloc(sizeof(bool) * (cnfshudu->boolCount + 1));
                                    for (int i = 1; i <= cnfshudu->boolCount; i++)
                                        value[i] = TRUE;   
                                    LARGE_INTEGER frequency, frequency_;    // 计时器频率
                                    LARGE_INTEGER start, start_, end, end_; // 设置时间变量
                                    double time, time_;
                                    // 未优化的时间
                                    QueryPerformanceFrequency(&frequency);
                                    QueryPerformanceCounter(&start); // 计时开始;
                                    int result = DPLL(newCnf, value, way);
                                    QueryPerformanceCounter(&end);                                       // 结束
                                    time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // 计算运行时间 
                                    // 输出SAT结果
                                    if (result == OK) // SAT
                                    {
                                        printf(" 有解\n\n");
                                        // 输出文字的真值
                                        for (int i = 1; i <= newCnf->boolCount; i++)
                                        {
                                            if (value[i] == TRUE)
                                                printf(" %-4d: TRUE\n", i);
                                            else
                                                printf(" %-4d: FALSE\n", i);
                                        }
                                    }
                                    else // UNSAT
                                        printf(" 无解\n");
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
        destroyCNF(cnf); // 退出时销毁CNF
    free(cnf);

    return ;
}
