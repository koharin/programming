#include <iostream>
#include <string>
#include <limits>
using namespace std;

int input(int *M){
    int count=0; // M ��� ������ ���� ����

    for(int i=0; ; i++){
        int n; 
        cin >> n;

        if(n == -1) break; // -1 �Է� ����
        else if(n < -1 || cin.fail()){ // -1 �̸� �Ǵ� 3�ڸ��� �ʰ��ϴ� ���� �Է����� �� �ٽ� �Է�, integer �̿� �ڷ����� �� ����ó��
            printf("0 �̻��� 3�ڸ� ���� ���� �Է����ּ���. (-1: �Է�����)\n");
            cin.clear(); // resets the error flags. empty the buffer X
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empty the buffer 
            i--; continue;
        }
        else if(n > 999) n %= 1000; // 3�ڸ� �ʰ��� ���� 1000���� ���� �������� n�� �ش�.
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
                // ����, ������ ���� ���� 3�ڸ� �ʰ� �˻�. 3�ڸ� �ʰ� �� mod 1000���� �� �Ҵ�
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
                if(R[operand2] > *count) *count = R[operand2] + 1; // M���� ����ؾ� �� ������ count ����
            }
            break;
            case 0: // 0ds : goto the location in register d unless register s contains 0
            {
                // ���� for loop���� PC++�� PC���� �����ϰ� �ǹǷ� 1 ���� ���� �ش�.
                if(R[operand2] != 0) PC = R[operand1]-1; 
                // else PC++ in loop condition
            }
            break;
        }
    }
}

int main(){
    int M[1000]={0}, R[10]={0}; // �����Ⱚ�� ��µ��� �ʵ��� 0���� �ʱ�ȭ
    int execute_count = 0; // ��ɾ� ���� Ƚ�� ī����

    int count =  input(M);
    interpret(M, R, &execute_count, &count);
    
    printf("=============================================\n");
    printf("��ɾ� ���� Ƚ��: %d\n", execute_count);
    printf("[�������� �� ���]\n");
    for(int i=0; i<10; i++) printf("R[%d] = %3d\n", i, R[i]);
    printf("[�޸� �� ���]\n");
    for(int i=0; i<count; i++) printf("M[%d] = %3d\n", i, M[i]);
}