#include "definition.hpp"

CNF readCNF(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件: %s\n", filename);
        return NULL;
    }
    
    CNF cnf = (CNF)malloc(sizeof(cnfNode));
    if (!cnf) {
        fclose(file);
        return NULL;
    }
    
    cnf->root = NULL;
    cnf->boolCount = 0;
    cnf->clauseCount = 0;
    
    char line[1024];
    clauseList lastClause = NULL;
    
    while (fgets(line, sizeof(line), file)) {
        // 跳过注释行和空行
        if (line[0] == 'c' || line[0] == '\n') {
            continue;
        }
        
        // 解析问题
        if (line[0] == 'p') {
            char format[10];
            sscanf(line, "p %s %d %d", format, &cnf->boolCount, &cnf->clauseCount);
            continue;
        }
        
        // 解析子句
        clauseNode* newClause = (clauseNode*)malloc(sizeof(clauseNode));
        if (!newClause) {
            fclose(file);
            destroyCNF(cnf);
            return NULL;
        }
        
        newClause->head = NULL;
        newClause->next = NULL;
        
        // 如果是第一个子句，设置为根节点
        if (!cnf->root) {
            cnf->root = newClause;
            lastClause = newClause;
        } else {
            lastClause->next = newClause;
            lastClause = newClause;
        }
        
        // 解析文字
        char* token = strtok(line, " \t\n");
        literalList lastLiteral = NULL;
        
        while (token) {
            int literal = atoi(token);
            
            // 遇到0表示子句结束
            if (literal == 0) {
                break;
            }
            
            literalNode* newLiteral = (literalNode*)malloc(sizeof(literalNode));
            if (!newLiteral) {
                fclose(file);
                destroyCNF(cnf);
                return NULL;
            }
            
            newLiteral->literal = literal;
            newLiteral->next = NULL;
            
            if (!newClause->head) {
                newClause->head = newLiteral;
            } else {
                lastLiteral->next = newLiteral;
            }
            
            lastLiteral = newLiteral;
            token = strtok(NULL, " \t\n");
        }
    }
    printf("读取完成！\n");
    fclose(file);
    return cnf;
}

// 销毁CNF结构
void destroyCNF(CNF cnf) {
    if (!cnf) return;
    
    clauseList currentClause = cnf->root;
    while (currentClause) {
        clauseList nextClause = currentClause->next;
        
        literalList currentLiteral = currentClause->head;
        while (currentLiteral) {
            literalList nextLiteral = currentLiteral->next;
            free(currentLiteral);
            currentLiteral = nextLiteral;
        }
        
        free(currentClause);
        currentClause = nextClause;
    }
    
    free(cnf);
}

// 打印CNF结构
void printCNF(CNF cnf) {
    if (!cnf) {
        printf("CNF为空\n");
        return;
    }
    
    printf("p cnf %d %d\n", cnf->boolCount, cnf->clauseCount);
    
    clauseList currentClause = cnf->root;
    while (currentClause) {
        literalList currentLiteral = currentClause->head;
        
        while (currentLiteral) {
            printf("%d ", currentLiteral->literal);
            currentLiteral = currentLiteral->next;
        }
        
        printf("0\n");
        currentClause = currentClause->next;
    }
}
