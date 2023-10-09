# 게임 수학 정리 문서
게임 개발에 필요한 수학 개념에 대해 정리한 문서입니다.

# 목차
* [1. 수와 집합](#1-수와-집합)
    * [1.1. 연산과 수의 구조](#11-연산과-수의-구조)
    * [1.2. 수의 구조](#12-수의-구조)
    * [1.3. 수의 표현](#13-수의-표현)
* [2. 함수](#2-함수)
    * [2.1. 함수의 개념과 종류](#21-함수의-개념과-종류)
    * [2.2. 합성함수](#22-합성함수)

# 1. 수와 집합
게임을 구성하는 가상 세계를 이해하기 위한 첫걸음은 ***집합***(Set)이라는 개념으로 수를 이해하는 것이다.   
의무교육에서 배운 집한은 서로 구분되는 ***원소***(Element)로 구성된 묶음을 의미한다.  
이러한 집합론을 ***소박한 집합론***(Native set theory)이라고 한다.

소박한 집한론의 관점에서는 용도에 따라 수집합을 정의하여 구분하는데, 대표적으로는 자연수, 정수, 유리수, 실수, 복소수, 사원수 등이 있다.     
각 수집합은 [표 1-1](#표-1-1-다양한-수집합에-대응하는-기호)와 같이 인간의 언어를 통해 대상 집합을 구분할 수 있게 정의하고, 각 집합마다 고유한 기호를 사용한다.

###### 표 1-1 다양한 수집합에 대응하는 기호
|분류|정의|기호|
|---|---|---|
|자연수|물건을 세거나 순서를 지정하기 위해 사용하는 수의 집합|N|
|정수|자연수와 자연수의 음수 0을 포함하는 수의 집합|Z|
|유리수|분모가 0이 아닌 두 정수의 비율 혹은 분수로 나타낼 수 있는 집합|Q|
|무리수|두 정수 비 혹은 분수로 나타낼 수 있는 수의 집합|I|
|실수|유리수와 무리수를 포함하는 수의 집합|R|
|복소수|실수와 제곱하면 -1이 되는 허수 단위 $i$를 조합해 $a + bi$ ($a, b$는 실수) 형태로 표현하는 수의 집합|C|
|사원수|실수와 제곱하면 -1이 되는 세 허수 단위 $i, j, k$를 조합해 $a + bi + cj + dk$ ($a, b, c, d$는 실수) 형태로 표현하는 수의 집합|H|

이렇게 소박한 집합론으로 정의한 수집합의 관계는 다음 [그림 1-1](#그림-1-1-집합과-원소의-관계)과 같이 벤 다이어그램으로 도식화할 수 있다.

###### 그림 1-1 집합과 원소의 관계
![집합과 원소의 관계](/img/집합과원소의관계.jpg)

소박한 집합론은 인간의 언어로 집합을 정의하기 때문에, ***보편적인 관념에 의존할 수밖에 없다***.   
예를 들어 자연수를 사용해 일상 생활에서 물건을 세는 데 우리는 아무 불편함이 없지만, 자연수의 체계는 어떻게 구성되어 있고 집합의 특징이 무엇인지 분석하고 싶다면 물건을 센다는 개념부터 명확하게 정의해야 한다.  
수가 가지는 특징을 분석하고 이를 확장해 가상 공간이라는 고차원의 체계를 만들 수 있다.

이러한 작업을 위해서는 집합의 성질을 참과 거짓으로 명확하게 구분해 줄 수 있는 ***명제***가 필요하다.  
명제 중에서 ***증명할 필요가 없는 기본 명제***를 ***공리***(Axiom)라고 하는데, ***공리를 기반으로 대상을 구분하는 집합론***을 ***공리적 집합론***(Axiomatic settheory)이라고 한다.  
공리적 집합론에서는 ***수가 가지는 연산에 대한 공리를 기반으로 수를 분류한다***.  

# 1.1. 연산과 수의 구조
***수집합의 고유한 특징***은 ***원소를 이용해 연산***을 한다는 점이다.  
대표적인 연산으로는 덧셈, 뺄셈, 곱셈, 나눗셈의 사칙연산이 있으며, 이들은 두 개의 원소를 사용해 새로운 원소를 만들어내기 때문에 ***이항연산***(Binary operation)이라고도 한다.   
이항연산의 개념은 [그림 1-2](#그림-1-2-이항연산의-개념)과 같이 표현할 수 있다.

###### 그림 1-2 이항연산의 개념
![이항연산의 개념](/img/)

같은 집합에 속한 두 수를 투입한 이항연산의 결과가 항상 투입한 집합에 속한다면, 그 이항연산은 해당 ***집합에 대해 닫혀 있다***(Closure)고 한다.  
그리고 이항연산은 ***교환법칙***(Commutative law), ***결합법칙***(Associative law), ***분배법칙***(Distributive law)이라는 3가지 성질을 지닌다.

첫 번째로 교환법칙은 임의의 두 수 $a$와 $b$를 연산할 때 ***순서에 관계없이 항상 동일한 결과가 나오는 성질***을 말한다.
$$a + b = b + a$$
$$a \cdot b = b \cdot a$$

두 번째로 결합법칙은 ***연산이 두 번 이상 연속될 때, 앞의 연산을 먼저 계산한 결과와 뒤의 연산을 계산한 결과가 같은 성질***을 의미한다.
$$(a + b) + c = a + (b + c)$$
$$(a \cdot b) \cdot c = a \cdot (b \cdot c)$$

세 번째로 분배법칙은 ***서로 다른 2가지 연산***에 대해 다음의 규칙이 성립되는 것이다.
$$a \cdot (b + c) = a \cdot b + a \cdot c$$
$$(b + c) \cdot a = b \cdot a + c \cdot a$$

여기서 1번 식은 ***좌분배법칙***, 2번 식은 ***우분배법칙***이라고 하는데, 이 두 가지를 모두 만족하면 분배법칙을 만족한다고 한다.

닫혀 있다는 개념과 세 가지 연산의 성질에 이어, 이항연산이 가지는 특징은 ***항등원***(Identity)과 ***역원***(Inverse)이다.   
항등원이란 ***임의의 수와의 연산 결과를 항상 동일한 수로 만들어주는 특별한 수다***.     
[그림 1-3](#그림-1-3-항등원의-개념)에서 원소 $b$는 항등원이다.

###### 그림 1-3 항등원의 개념
![항등원의 개념](/img/)

실수 집합 R에서의 덧셈 연산을 예로 들어보자.    
실수 집합에서 덧셈의 항등원이란 다음 식 1과 같이 미지수 $a$에 항등원 $b$를 더했을 때 결괏값이 $a$ 그대로 나오는 수를 의미하므로, ***덧셈의 항등원은 0***이 된다.  
그렇다면 실수 집합에서 ***곱셈의 항등원은 1***이 되는 것도 유추할 수 있다.
$$a + 0 = a$$
$$a \cdot 1 = a$$

역원이란 ***임의의 수와의 연산 결과를 항상 항등원으로 만들어주는 특별한 수다***.    
항등원과 역원의 개념을 비교하면 [그림 1-4](#그림-1-4-항등원과-역원-개념의-비교)와 같다.

###### 그림 1-4 항등원과 역원 개념의 비교
![항등원과 역원 개념의 비교](/img/)

이항연산에 사용하는 임의의 수를 $a$로 지정했을 때, 결과가 항등원이 되는 덧셈과 곱셈의 역원은 각각 다음과 같다.
$$a + (-a) = 0$$
$$a \cdot \frac{1}{a} = 1$$

***항등원은 덧셈이나 곱셈에 대해 각각 0과 1로 고정***되어 있지만 ***역원은 덧셈이나 곱셈에 주어진 수에 따라 그 값이 달라진다***.    
이러한 역원은 연산에 따라 일정한 패턴을 보인다.     
즉 덧셈 역원은 주어진 수에서 항상 부호가 반대인 수가 되므로 ***반대수***(Opposite number)라고 부른다. 
또한 곱셈 역원은 분자가 1이고 분모는 주어진 수가 되므로 ***역수***(Reciprocal)라고도 일컫는다.    
단 ***분모가 0이 되는 분수는 존재하지 않으므로 0의 곱셈 역원은 없다***.

이항연산의 성질을 정리하면 [표 1-2](#표-1-2-이항연산의-성질)와 같다.

###### 표 1-2 이항연산의 성질
|성질|정의|
|---|---|
|닫혀 있음|어떤 집합에서 두 원소를 사용한 이항연산의 결과가 항상 그 집합에 속하는 성질|
|교환법칙|두 원소의 좌우 순서를 바꿔도 결과가 동일한 성질|
|결합법칙|세 원소의 연산 순서를 바꿔도 결과가 동일한 성질|
|분배법칙|두 이항연산에 대해 $a \cdot (b + c) = a \cdot b + a \cdot c$와 $(b + c) \cdot a = b \cdot a + c \cdot a$의 결과가 나오는 성질|
|항등원|주어진 원소와의 이항연산 결과가 언제나 주어진 원소가 되는 특별한 원소. 실수에서 덧셈의 항등원은 0이고 곱셈의 항등원은 1이다.|
|역원|주어진 원소와의 이항연산 결과가 언제나 항등원이 되는 특별한 원소. 실수에서 덧셈의 역원은 반대수. 곱셈의 역원은 역수라고 부른다.|

# 1.2. 수의 구조
이항연산의 성질을 바탕으로 공리를 구축하고, 공리를 사용해 기존의 수집합을 새롭게 분류한다.

1. 연산에 대해 닫혀 있다.
2. 연산에 대해 결합법칙이 성립한다.
3. 연산에 대한 항등원이 존재한다.
4. 연산에 대한 역원이 존재한다.
5. 연산에 대해 교환법칙이 성립한다.

정수 집합 Z의 구조를 이와 같은 공리 체계에서 분석하면, 정수의 덧셈(+)은 위 공리를 모두 만족한다.    
정수끼리 더한 결과는 항상 정수에 속하고, 결합법칙이 성립하면서 항등원 0과 임의의 수 $a$에 대한 역원 $-a$가 언제나 존재하기 때문이다.    
그러나 정수의 뺄셈(-)은 위 공리를 모두 만족하지 못한다.     
뺄셈은 교환법칙이 성립하지 않기 때문이다.

연산을 하나 더 추가해, 두 개의 연산에 대한 공리를 생각해보자.

6. 두 번째 연산에 대해 닫혀 있다.
7. 두 번째 연산에 대해 결합법칙이 성립한다.
8. 첫 번째 연산과 두 번째 연산에 대해 분배법칙이 성립한다.
9. 두 번째 연산에 대해 교환법칙이 성립한다.
10. 두 번째 연산에 대해 항등원이 존재한다.
11. 두 번째 연산에 대해 역원이 존재한다(단 0은 제외).

정수 집합 Z에 곱셈 연산을 추가하고 이와 같은 공리를 만족하는지 살펴보자.    
정수 집합은 곱셈에 닫혀 있고, 결합법칙과 분배법칙이 성립하며 교환법칙도 성립한다.   
하지만 정수 집합의 원소 $a$에 대한 곱셈의 역원은 $\frac{1}{a}$인데 이는 정수가 아니기 때문에 11번의 공리를 만족하지 못한다.     
따라서 정수 집합의 덧셈과 곱셈은 이들 공리를 모두 만족하지 못한다.

덧셈과 곱셈 연산에 대해 11가지 공리를 모두 만족하는 수 집합은 어떤 것이 있는지 생각해보자.  
***덧셈에 대한 역원이 존재하지 않는 자연수***(N)와 ***곱셈에 대한 역원이 존재하지 않는 정수***(Z)는 이를 만족하지 못한다.   
하지만 ***유리수***(Q), ***실수***(R)는 ***곱셈의 역원이 존재***하기 때문에 덧셈과 곱셈 두 연산에 대해 앞서 열거한 11가지 공리를 모두 만족한다.

***공리적 집합론에서 두 연산에 대해 1번부터 11번까지의 공리를 모두 만족하는 수 집합은 체(Field)의 구조를 지닌다고 표현한다***.    
유리수(Q), 실수(R)와 같이 ***체의 구조를 가지는 수 집합은 특별한 예외 상황 없이 덧셈과 곱셈을 안전하고 자유롭게 사용할 수 있다***고 볼 수 있다.   
콘텐츠를 담는 가상 세계를 구축하기 위해서 특정한 수 집합을 지정해 사용하는 것이 아닌, 체의 구조를 기반으로 체계를 확장해 공간의 구조를 생성한다.

사칙 연산을 구성하는 나머지 연산인 뺄셈과 나눗셈은 체의 구조를 만족하는지 살펴보자.     
***뺄셈과 나눗셈은 교환법칙을 만족하지 않기 때문에 체의 구조를 지니지 못한다***.
$$a - b \neq b - a$$
$$a \div b \neq b \div a$$

이에 대한 해결책은 ***뺄셈 대신 덧셈의 역원을 사용***하고 ***나눗셈 대신 곱셈의 역원을 사용***하는 것이다.

실수 집합에서 덧셈의 역원은 반대수, 곱셈의 역원은 역수였다.     
뺄셈과 나눗셈 대신 덧셈과 곱셈의 역원을 사용하면 교환법칙이 성립하면서 같은 결과를 만들어낸다.
$$a + (-b) = (-b) + a$$
$$a \cdot \frac{1}{b} = \frac{1}{b} \cdot a$$

그렇기 때문에 수 집합의 구조를 분석할 때는 덧셈과 곱셈의 두 가지 연산에 대해서만 살펴보는 것으로 충분하다.

정리하면, ***체는 사칙연산이 자유로이 시행될 수 있고 산술의 잘 알려진 규칙들을 만족하는 수의 구조다***.     

# 1.3. 수의 표현
실수(R)를 대응시켜 표현한 직선을 수직선(Number line)이라 하며 [그림 1-5](#그림-1-5-수직선의-예)과 같이 표현한다.    
> 참고: 수를 표현하는 수직선(Number line)은 직각으로 만나는 직선을 의미하는 수직선(Perpendicular line)과 동음이의어다.

###### 그림 1-5 수직선의 예
![수직선의 예](/img/)

실수의 모든 요소는 상호 간에 크기를 비교할 수 있다.     
***더 큰 수는 오른쪽에 표시하는 규칙을 사용해 실수의 모든 원소는 수직선 상에 자신의 고유한 위치를 갖게 된다***.   
따라서 하나의 실수를 시각화할 때는 그 수의 고유한 위치에 점을 찍어 표현한다.    
[그림 1-6](#그림-1-6-점으로-수를-표현하는-방법)에서는 -2보다 큰 수 2가 수직선에서 오른쪽에 위치함을 알 수 있다.

###### 그림 1-6 점으로 수를 표현하는 방법
![점으로 수를 표현하는 방법](/img/)

***수직선은 0을 기준으로 양수와 음수라는 두 개의 체계가 서로 대칭되어 있는 것으로 해석할 수 있다***.  
이러한 관점에서 하나의 수는 [그림 1-7](#그림-1-7-화살표로-수를-표현하는-방법)과 같이 원점에서부터 크기와 방향을 가진 화살표로도 표현할 수 있다.

###### 그림 1-7 화살표로 수를 표현하는 방법
![화살표로 수를 표현하는 방법](/img/)

이와 같이 수가 지니는 방향의 속성은 부호를 사용해 나타내며 크기의 속성은 원점으로부터의 거리를 의미한다.    
***어떤 수의 원점으로부터의 거리는 수직 막대(Vertical bar) 기호를 써서 나타내는데, 이를 절댓값(Absolute value)이라고 한다***.
$$|-3| = 3$$

***물체에 힘을 가해 이동하거나, 크기를 늘리는 작업은 덧셈과 곱셈 연산으로 해석할 수 있다***.  
이항연산에서 왼쪽 항의 수를 물체를 구성하는 점으로 보고, 오른쪽 항의 수를 점을 이동시키는 힘으로 보면 덧셈 연산은 [그림 1-8](#그림-1-8-점의-이동으로-표현하는-덧셈-연산)과 같이 점을 평행 이동시키는 작업으로 해석할 수 있다.    
예를 들면 어떤 수와 -5와의 합은 수의 위치를 왼쪽 방향으로 5칸만큼 이동시키는 작업이고, 2와의 합은 오른쪽 방향으로 2칸만큼 이동시키는 작업이다.

###### 그림 1-8 점의 이동으로 표현하는 덧셈 연산
![점의 이동으로 표현하는 덧셈 연산](/img/)

그리고 곱셈 연산은 [그림 1-9](#그림-1-9-크기와-방향의-변화로-표현하는-곱셈-연산)와 같이 원점을 기준으로 점의 위치를 지정된 배율만큼 늘리고 대칭시키는 작업으로 해석할 수 있다.  
예를 들면 어떤 수와 2의 곱은 원점으로부터 거리를 같은 방향으로 2배로 키우는 작업이고, -2와의 곱은 원점으로부터 거리를 2배로 늘린 후 반대쪽으로 대칭시키는 작업으로 볼 수 있다.  
왼쪽 항의 수가 가진 크기를 오른쪽 수가 가진 크기의 배율로 늘리거나 줄인 후 오른쪽 수의 부호가 양의 부호인 경우 원 방향을 유지하고, 음수인 경우 반대 방향으로 대칭시키는 작업이 곱셈 연산이다.

###### 그림 1-9 크기와 방향의 변화로 표현하는 곱셈 연산
![크기와 방향의 변화로 표현하는 곱셈 연산](/img/)

# 2. 함수
***함수(Function)란 두 집합에서 첫 번째 집합의 모든 원소가 빠짐없이 두 번째 집합의 어떤 원소에 대응하는 관계를 의미한다***.

# 2.1. 함수의 개념과 종류
두 집합을 $X$와 $Y$라는 기호로 지정하고, 집합 $X$의 원소를 $x$, 집합 $Y$의 원소를 $y$라 할 때 $X$에서 $Y$로 대응되는 함수를 $y = f(x)$로 나타낸다.  
두 집합의 대응 관계는 [그림 1-10](#그림-1-10-함수의-개념과-기호)과 같다.

###### 그림 1-10 함수의 개념과 기호
![함수의 개념과 기호](/img/)

두 집합의 요소가 서로 대응된다고 모두 함수로 인정받는 것은 아니고, 다음 두 규칙이 성립돼야 한다.

1. 첫 번째 집합의 모든 원소에 대한 대응 관계가 존재해야 함
2. 첫 번째 집합의 원소는 두 번째 집합의 원소에만 대응되어야 함

[그림 1-11](#그림-1-11-함수가-아닌-두-집합의-대응-관계)을 예시로 보면, 집합 $X$의 원소 중 3과 4는 대응 관계가 없고 원소 2는 집합 $Y$의 두 원소($B$와 $C$)에 대응된다.     
따라서 예시에서 나타난 두 집합의 대응 관계는 함수가 아니다.

###### 그림 1-11 함수가 아닌 두 집합의 대응 관계
![함수가 아닌 두 집합의 대응 관계](/img/)

왼쪽의 집합과 오른쪽의 집합이 가져야 하는 조건이 다르기 때문에 함수에서 정의된 용어를 사용해 두 집합이 가진 대응 관계를 명확하게 전달해야 한다.     
***함수에서 왼쪽에 위치한 첫 번째 집합을 정의역(Domain)이라고 하고, 오른쪽에 위치한 두 번째 집합을 공역(Codomain)이라 한다***.

함수 용어를 사용해 대응 관계를 표현한다면, ***정의역의 모든 원소는 공역의 원소에 대응되어야 한다***.  
하지만 ***공역의 모든 원소가 정의역에 대응할 필요는 없다***.  
그렇기 때문에 ***정의역에 대응되는 공역의 원소만 따로 모아 부분집합(Subset)을 형성할 수 있는데, 이를 치역(Range)이라고 부른다***.     
[그림 1-12](#그림-1-12-정의역-공역-치역의-개념)는 정의역, 공역, 치역의 개념과 관계를 표현한다.

###### 그림 1-12 정의역, 공역, 치역의 개념
![정의역, 공역, 치역의 개념](/img/)

또한 ***함수에 사용하는 정의역의 요소를 입력(Input), 입력에 대응하는 공역의 요소를 출력(Output)이라고 한다***.    
이러한 함수의 개념은 [그림 1-13](#그림-1-13-함수의-개념을-기계로-표현하기)과 같은 형태로도 표현할 수 있다.

###### 그림 1-13 함수의 개념을 기계로 표현하기
![함수의 개념을 기계로 표현하기](/img/)

정의역과 공역이 서로 대응되는 형태에 따라 함수를 여러 종류로 구분할 수 있다.

## 전사함수
***전사함수(Surjection)는 공역의 모든 요소가 정의역에 대응되는 함수를 의미한다***.    
[그림 1-14](#그림-1-14-전사함수의-예시)와 같이 공역과 치역이 동일한 함수다.   
> 참고: 위로의 함수(Onto)라고도 부름

###### 그림 1-14 전사함수의 예시
![전사함수의 예시](/img/)

[그림 1-15](#그림-1-15-전사함수가-아닌-예시)는 공역과 치역이 서로 다르므로 전사함수가 아니다.

###### 그림 1-15 전사함수가 아닌 예시
![전사함수가 아닌 에시](/img/)

## 단사함수
***단사함수(Injection)는 정의역과 공역의 요소가 일대일로 대응되는 함수를 의미한다***.     
[그림 1-16](#그림-1-16-단사함수-예시)은 정의역의 모든 요소가 공역의 요소에 일대일로 대응되므로 단사함수다.
> 참고: 일대일 함수(One-to-One)라고도 부름

###### 그림 1-16 단사함수 예시
![단사함수 예시](/img/)

[그림 1-17](#그림-1-17-단사함수가-아닌-예시)은 정의역의 두 요소가 공역의 한 요소에 대응되기 때문에 일대일 대응이 아니므로 단사함수가 아니다.

###### 그림 1-17 단사함수가 아닌 예시
![단사함수가 아닌 예시](/img/)

## 전단사함수
***전단사함수(Bijection, One-to-One and Onto)는 정의역과 공역의 모든 요소가 빠짐없이 일대일로 대응되는 함수를 의미한다***.    
[그림 1-18](#그림-1-18-전단사함수-예시)과 같이 전사함수와 단사함수의 두 가지 성질을 모두 만족하면 전단사함수라 할 수 있다.

###### 그림 1-18 전단사함수 예시
![전단사함수 예시](/img/)

# 2.2. 합성함수
함수의 대응 관계를 확장해 다수 집합의 대응 관계로 발전시킬 수도 있다.   
***2개의 함수를 연쇄적으로 이어서 하나의 함수로 만드는 연산을 함수의 합성(Function composition)이라 한다***.  
[그림 1-19](#그림-1-19-합성함수의-예시)와 같이 세 집합 $X, Y, Z$ 사이에 두 함수 $f(x)$와 $g(y)$가 존재하는 상황을 가정해보자.

###### 그림 1-19 합성함수의 예시
![합성함수의 예시](/img/)

두 함수 $f(x)$와 $g(y)$를 연쇄적으로 이어 합성함수를 만들면, [그림 1-20](#그림-1-20-합성함수의-결과)과 같이 중간에 위치한 집합 $Y$를 생략하고 집합 $X$와 $Z$의 직접적인 대응 관계를 표현할 수 있다.   
이러한 합성함수는 $g \circ f$ 혹은 $g(f(x))$로 표시한다.    
***먼저 실행되는 함수 $f$가 합성함수 기호($\circ$)의 오른쪽에 놓인다는 점에 유의해야 한다***.     
> 참고: 합성함수는 $g \circ f$는 $g$ 써클 $f$로 부르는데, 대응 순서에 맞춰서 $g$ 애프터 $f$라고도 부른다.

###### 그림 1-20 합성함수의 결과
![합성함수의 결과](/img/)

이번에는 [그림 1-21](#그림-1-21-4개-집합과-3개-함수로-구성된-대응-관계)과 같이 집합과 함수를 하나씩 더 추가한 대응 관계를 생각해보자.

###### 그림 1-21 4개 집합과 3개 함수로 구성된 대응 관계
![4개 집합과 3개 함수로 구성된 대응 관계](/img/)

이 상황에서는 두 합성함수에 대한 경우의 수를 [그림 1-22](#그림-1-22-세-함수로부터-만들어지는-두-합성함수에-대한-경우의-수)의 (a)와 (b)와 같이 생각할 수 있다.

###### 그림 1-22 세 함수로부터 만들어지는 두 합성함수에 대한 경우의 수
![세 함수로부터 만들어지는 두 합성함수에 대한 경우의 수](/img/)

[그림 1-22](#그림-1-22-세-함수로부터-만들어지는-두-합성함수에-대한-경우의-수)의 (a)와 (b)의 두 합성함수가 남은 함수와 다시 합성하는 경우는 각각 [그림 1-23](#그림-1-23-합성함수의-합성-결과)의 (a)와 (b)와 같이 전개될 것이다.

###### 그림 1-23 합성함수의 합성 결과
![합성함수와의 합성 결과](/img/)

[그림 1-23](#그림-1-23-합성함수의-합성-결과)의 (a)와 (b)의 결과는 동일한 대응 관계를 가짐을 볼 수 있다.  
***합성 함수를 이항연산으로 규정하면, 합성 함수는 결합법칙이 성립한다***.

# 2.3. 항등함수와 역함수
수의 연산에서 다룬 항등원, 역원과 동일한 개념이 함수에도 존재한다.  
[그림 1-24](#그림-1-24-항등함수의-예시)와 같이 ***정의역과 공역이 동일한 값으로 대응되는 함수를 항등함수(Identity function)라고 하며 기호 $id$로 나타낸다***.

###### 그림 1-24 항등함수의 예시
![항등함수의 예시](/img/)

항등함수는 [1.1. 연산과 수의 구조](#11-연산과-수의-구조)에서 배운 연산의 항등원과 동일한 역할을 수행한다.  
합성함수를 사용해 함수에 연산의 개념을 도입하면 세 집합의 대응 관계는 [그림 1-25](#그림-1-25-항등함수를-사용한-합성함수)와 같이 표현할 수 있다.

###### 그림 1-25 항등함수를 사용한 합성함수
![항등함수를 사용한 합성함수](/img/)

(a)를 수식으로 나타내면 $id \circ f = f$이고 (b)를 수식으로 나타내면 $f \circ id = f$가 되는데 ***항등함수는 어느 위치에 있든지 합성의 결과는 원 함수와 동일한 대응 관계를 나타낸다***.

수의 역원 개념과 동일하게 합성함수의 대응 결과가 항등함수가 되는 경우를 생각해 보자.    
[그림 1-26](#그림-1-26-합성함수의-결과가-항등함수가-되는-경우)의 (a)와 같은 대응 관계가 있다고 생각한다면, 이를 합성해 간추린 결과는 (b)와 같이 서로 동일한 원소끼리 대응될 것이다.

###### 그림 1-26 합성함수의 결과가 항등함수가 되는 경우
![합성함수의 결과가 항등함수가 되는 경우](/img/)

[그림 1-26](#그림-1-26-합성함수의-결과가-항등함수가-되는-경우)의 (a)의 $g(y)$와 같은 함수를 역함수(Inverse function)라고 한다.     
***역함수는 위 첨자를 붙여 $f^{-1}$로 표기***하며 어떤 함수와 역함수를 합성한 결과는 (b)와 같이 언제나 항등함수가 된다.   
이를 수식으로 나타내면 다음과 같다.
$$f^{-1} \circ f = id$$
$$f \circ f^{-1} = id$$

***역함수는 두 집합의 대응 관계를 뒤집어 공역 $Y$에서 정의역 $X$로 대응하는 함수로도 생각할 수 있다***.   
이 개념을 도식화하면 [그림 1-27](#그림-1-27-역함수의-개념과-기호)과 같다.

###### 그림 1-27 역함수의 개념과 기호
![역함수의 개념과 기호](/img/)

***역함수에서 주의할 점은 모든 함수가 역함수를 갖지는 않는다는 사실이다***.   
[그림 1-28](#그림-1-28-전사함수와-단사함수의-역함수)의 (a)에서 보여지는 전사함수는 하나의 원소가 두 개의 원소에 대응되기 때문에 함수의 기본 조건을 만족하지 못하고, (b)의 단사함수는 정의역의 모든 원소가 대응하지 않기 때문에 이들의 역함수는 함수의 조건을 만족하지 못한다.

###### 그림 1-28 전사함수와 단사함수의 역함수
![전사함수와 단사함수의 역함수](/img/)

하지만 전단사함수의 경우에는 [그림 1-29](#그림-1-29-전단사함수의-역함수)과 같이 모든 경우에서 함수의 조건을 만족하기 때문에 역함수가 보장된다.    
***어떤 함수가 역함수를 가지기 위해서는 반드시 전단사함수의 형태가 되어야 한다***.

###### 그림 1-29 전단사함수의 역함수
![전단사함수의 역함수](/img/)

합성함수에 역함수의 개념을 적용해보자.  
[그림 1-30](#그림-1-30-합성함수의-예시)의 (a)에 세 집합 $X, Y, Z$ 대상으로 생성된 두 전단사함수 $f, g$를 나타냈다.    
이를 합성한 결과는 (b)가 될 것이다.

###### 그림 1-30 합성함수의 예시
![합성함수의 예시](/img/)

여기서 [그림 1-30](#그림-1-30-합성함수의-예시)의 (b)의 합성함수 $g \circ f$를 거꾸로 뒤집은 역함수 $(g \circ f)^{-1}$는 [그림 1-31](#그림-1-31-합성함수의-역함수)과 같은 대응관계를 가진다고 볼 수 있다.

###### 그림 1-31 합성함수의 역함수
![합성함수의 역함수](/img/)

이는 [그림 1-32](#그림-1-32-합성함수의-역함수의-분석)와 같이 두 함수의 역함수 $f^{-1}$과 $g^{-1}$ 반대 순서로 합성한 결과로 볼 수 있다.

###### 그림 1-32 합성함수의 역함수의 분석
![합성함수의 역함수의 분석](/img/)

이러한 합성함수의 역함수가 가지는 성질은 아래와 같은 식으로 정리된다.
$$(g \circ f)^{-1} = f^{-1} \circ g^{-1}$$