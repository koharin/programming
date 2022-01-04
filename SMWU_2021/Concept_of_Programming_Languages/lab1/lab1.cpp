#include <iostream>
#include <string>
#include <limits>
using namespace std;

int input(int *M){
    int count=0; // M 출력 범위에 대한 변수

    for(int i=0; ; i++){
        int n; 
        cin >> n;

        if(n == -1) break; // -1 입력 종료
        else if(n < -1 || cin.fail()){ // -1 미만 또는 3자리를 초과하는 수를 입력했을 때 다시 입력, integer 이외 자료형일 때 오류처리
            printf("0 이상의 3자리 이하 수를 입력해주세요. (-1: 입력종료)\n");
            cin.clear(); // resets the error flags. empty the buffer X
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empty the buffer 
            i--; continue;
        }
        else if(n > 999) n %= 1000; // 3자리 초과의 수는 1000으로 나눈 나머지로 n을 준다.
        M[i] = n; count++;
    }
    return count;
}

void interpret(int *M, int *R, int *execute_count, int *count){
    int PC = 0; 

    for(;;PC++){
        int opcode = int(M[PC]/100); // opcode digit
        int operand1 = int(M[PC]%100/10); // operand1 digit 
        int operand2 = M[PC] % 10; // operand2 digit

        (*execute_count)++; 
        switch(opcode){
            case 1: 
            {
                // return if halt
                if(operand1 == 0 && operand2 == 0) return; 
            }
            break;
            case 2: // 2dn : set register d to n
            {
                R[operand1] = operand2;
            }
            break;
            case 3: // 3dn : add n to register d
            {
                // 덧셈, 곱셈에 대해 길이 3자리 초과 검사. 3자리 초과 시 mod 1000으로 값 할당
                if(to_string(R[operand1] + operand2).length() > 3) R[operand1] = (R[operand1] + operand2) % 1000;
                else R[operand1] += operand2;
            }
            break;
            case 4: // 4dn : multiply register d by n
            {
                if(to_string(R[operand1] * operand2).length() > 3) R[operand1] = (R[operand1] * operand2) % 1000;
                else R[operand1] *= operand2;
            }
            break;
            case 5: // 5ds : set register d to the value of register s
            {
                R[operand1] = R[operand2];
            }
            break;
            case 6: // 6ds : add the value of register s to register d
            {
                if(to_string(R[operand1] + R[operand2]).length() > 3) R[operand1] = (R[operand1] + R[operand2]) % 1000;
                else R[operand1] += R[operand2];
            }
            break;
            case 7: // 7ds : multiply register d by the value of register s
            {
                if(to_string(R[operand1] * R[operand2]).length() > 3) R[operand1] = (R[operand1] * R[operand2]) % 1000;
                else R[operand1] *= R[operand2];
            }
            break;
            case 8: // 8da : set register d to the value in RAM whose address is in register a
            {
                R[operand1] = M[R[operand2]];
            }
            break;
            case 9: //  9sa : set the value in RAM whose address is in register a to that of register s
            {
                M[R[operand2]] = R[operand1];
                if(R[operand2] > *count) *count = R[operand2] + 1; // M에서 출력해야 할 범위인 count 갱신
            }
            break;
            case 0: // 0ds : goto the location in register d unless register s contains 0
            {
                // 이후 for loop에서 PC++로 PC값이 증가하게 되므로 1 작은 값을 준다.
                if(R[operand2] != 0) PC = R[operand1]-1; 
                // else PC++ in loop condition
            }
            break;
        }
    }
}

int main(){
    int M[1000]={0}, R[10]={0}; // 쓰레기값이 출력되지 않도록 0으로 초기화
    int execute_count = 0; // 명령어 실행 횟수 카운팅

    int count =  input(M);
    interpret(M, R, &execute_count, &count);
    
    printf("=============================================\n");
    printf("명령어 실행 횟수: %d\n", execute_count);
    printf("[레지스터 값 출력]\n");
    for(int i=0; i<10; i++) printf("R[%d] = %3d\n", i, R[i]);
    printf("[메모리 값 출력]\n");
    for(int i=0; i<count; i++) printf("M[%d] = %3d\n", i, M[i]);
}