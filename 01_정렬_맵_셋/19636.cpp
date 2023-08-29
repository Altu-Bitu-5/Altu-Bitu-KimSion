#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

//다이어트 함수 정의
//w0: 다이어트 전 체중 i0: 다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량 a: 다이어트 기간 일일 활동 대사량 d: 다이어트 기간 t: 기초 대사량 변화 역치
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    //다이어트 기간 동안 반복
    while (d--) {
        // 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        w1 += i - (m1 + a);
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화 (m2만 변화)
        if (abs(i - (m2 + a)) > t) {
            // [주의] 음수의 나눗셈에 주의: ⌊−5 / 2⌋를 수행하면 3이 나와야 하지만
            //                              C++에서 int i = (-5) / 2를 수행할 경우 -2가 나옴
            //                              => float끼리의 나눗셈으로 수행하고 소숫점 버림
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    return {w1, w2, m2}; //기초 대사량 변화 고려하지 않은 체중, 기초 대사량 변화 고려한 체중, 기초 대사량 변화 고려한 기초 대사량 반환
}

int main() {
    //w0: 다이어트 전 체중 i0: 다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량 a: 다이어트 기간 일일 활동 대사량
    int w0, i0, i, a;
    //d: 다이어트 기간 t: 기초 대사량 변화 역치
    int d, t;
    //final_weight: 
    int final_weight, final_meta;
    //변수 값 입력받음
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    //다이어트 함수 호출
    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t); //입력 받았던 값을 함수 인자로 넘김
    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O 

    //일일 기초 대사량 변화 고려하지 않은 경우 결과 출력
    if (w1 <= 0) { //체중이 0 이하인 경우
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet\n";
    } else {
        cout << w1 << " " << m1 << "\n"; //Danger Diet가 아닌 경우 - 기초 대사량 변화를 고려하지 않았을 때의 다이어트 후 예상 체중과 일일 기초 대사량 출력
    }

    //일일 기초 대사량 변화 고려했을 때 결과와 요요 여부 출력
    if (w2 <= 0 || m2 <= 0) { //체중이 0 이하인 경우 또는 일일 기초 대사량이 0 이하인 경우
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << m2 << " "; //Danger Diet가 아닌 경우 - 기초 대사량 변화를 고려했을 때의 다이어트 후 예상 체중과 일일 기초 대사량 출력
        if (m2 < i0) { //기초 대사량이 i0보다 작은 경우 요요 현상 발생
            cout << "YOYO";
        } else { //요요 현상이 발생하지 않는 경우
            cout << "NO";
        }
    }
    return 0;
}