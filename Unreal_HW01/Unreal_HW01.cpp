#include <iostream>
#include <windows.h>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}


int main()
{
    //SetConsoleOutputCP(CP_UTF8);

    int state[4] = { 0 }; // 0 체력, 1 마나, 2 공격력, 3. 방어력
    int HPPotion = 0; // 체력 포션 선언
    int MPPotion = 0; // 마나 포션 선언
    int choice; // 스텟 메뉴 선택
    int level = 1; // 캐릭터 레벨
    int fight;

    while (true) // Hp 입력
    {

        cout << "HP와 MP를 입력하시오 ( 50↑): ";
        cin >> state[0] >> state[1];

        if (state[0] > 50 && state[1] > 50)
        {
            break;
        }
        else
            cout << "HP 및 MP는 50보다 커야합니다 다시 입력하시오." << endl;

    }

    while (true) // Hp 입력
    {

        cout << "공격력과 방어력를 입력하시오 ( 0↑): ";
        cin >> state[2] >> state[3];

        if (state[2] > 0 && state[3] > 0)
        {
            break;
        }
        else
            cout << "공격력 및 방어력은 0보다 커야합니다 다시 입력하시오." << endl;

    }

    setPotion(5, &HPPotion, &MPPotion); // 기본 포션 개수
    cout << "체력, 마나 포션이 5개씩 지급됩니다 " << endl;
    cout << "<<<스텟 관리 시스템>>>" << endl;
    cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 7.전투하기 / 0.나가기" << endl;

    while (true) // 기본 메뉴
    {

        cout << "선택: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "프로그램 종료\n"; return 0;

        case 1:
            if (HPPotion > 0)
            {
                state[0] += 20;
                HPPotion--;
                cout << "현재 HP: " << state[0] - 20 << " → " << state[0] << endl;
                cout << "남은 체력 포션의 개수: " << HPPotion << "개" << endl;
            }
            else
            {
                cout << "체력 포션을 보유하지 않았습니다" << endl;
            }
            break;

        case 2:
            if (MPPotion > 0)
            {
                state[1] += 20;
                MPPotion--;
                cout << "현재 MP: " << state[1] - 20 << " → " << state[1] << endl;
                cout << "남은 마나 포션의 개수: " << MPPotion << "개" << endl;
            }
            else
            {
                cout << "마나 포션을 보유하지 않았습니다" << endl;
            }
            break;

        case 3:
            state[2] *= 2;
            cout << "공격력이 2배 증가합니다" << endl;
            cout << "현재 공격력:" << state[2] << endl;
            break;

        case 4:
            state[3] *= 2;
            cout << "방어력이 2배 증가합니다" << endl;
            cout << "현재 방어력:" << state[3] << endl;
            break;

        case 5:
            cout << "레벨: " << level << "LV" << endl;
            cout << "HP: " << state[0] << endl;
            cout << "MP: " << state[1] << endl;
            cout << "공격력: " << state[2] << endl;
            cout << "방어력: " << state[3] << endl;
            cout << "남은 HP 포션: " << HPPotion << "개" << endl;
            cout << "남은 MP 포션: " << MPPotion << "개" << endl;
            break;

        case 6:
            level++;
            HPPotion++;
            MPPotion++;
            cout << "레벨 업" << endl;
            cout << "현재레벨: " << level << "LV" << endl;
            cout << "체력, 마나 포션이 1개씩 지급됩니다." << endl;
            break;

        case 7:
            cout << "---체력과 마나가 -100되는 기능 및 체력이 0이면 종료만 구현---" << endl;
            cout << "전장으로 떠나시겠습니까? 예[1], 아니오[2]" << endl;
            cin >> fight;

            if (fight == 1)
            {
                cout << "전장으로 출발!" << endl;

                // 체력/마나 감소
                if (state[0] > 100)
                    state[0] -= 100;
                else
                {
                    cout << "당신은 패배하였습니다" << endl;
                    return 0;
                }

                if (state[1] >= 100)
                    state[1] -= 100;
                else
                    state[1] = 0;

                cout << "전투 후 HP: " << state[0] + 100 << " → " << state[0] << endl;
                cout << "전투 후 MP: " << state[1] + 100 << " → " << state[1] << endl;
            }
            else if (fight == 2)
            {
                cout << "당신은 겁이 나서 돌아갑니다." << endl;
            }
            else
            {
                cout << "올바른 숫자를 입력하세요." << endl;
            }
            break;

        default:
            cout << "올바른 숫자를 입력하시오.\n";
            break;
        }
    }

    return 0;
}
