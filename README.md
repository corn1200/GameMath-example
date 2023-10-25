
> 참고: ***열 기준 행렬과 행 기준 행렬***     
행렬과 벡터의 곱셈을 수행하는 방식으로, 열 기준 행렬(Column major matrix)과 행 기준 행렬(Row major matrix) 두 가지가 있다.  
수학에서 행렬을 다룰 때는, 벡터를 열벡터로 나타내는 열 기준 행렬 방식을 주로 사용한다.
>
> $$
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix} \cdot
\begin{bmatrix}
x \\
y \\
\end{bmatrix} =
\begin{bmatrix}
ax + by \\
cx + dy \\
\end{bmatrix}
\> $$
>
> 컴퓨터에서 실제로 행렬을 응용할 때는, 행 기준 행렬을 사용하는 경우도 있다.    
행 기준으로 선형 변환을 수행할 때는 열 기준과 다르게 행렬과 벡터의 위치를 거꾸로 뒤집어서, 다음과 같이 벡터를 앞쪽에 두어야 행렬의 곱셈이 성립된다.
>
> $$
\begin{bmatrix}
x & y
\end{bmatrix} \cdot
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix} =
\begin{bmatrix}
ax + cy & bx + dy
\end{bmatrix}
\> $$
>
> 이와 같이 정방행렬 $A$의 요소를 열 기준 방식과 동일하게 배치한다면 행렬 곱셈의 결과는 다른 값이 나온다.   
>
> $$(ax + by, cx + dy) \neq (ax + cy, bx + dy)$$
>
> 원하는 결과는 $(ax + by, cx + dy)$이므로 열 기준 행렬 방식을 사용한다면 정방행렬 $A$의 요소는 다음과 같이 배치해야 할 것이다.
>
> $$
\begin{bmatrix}
x & y
\end{bmatrix} \cdot
\begin{bmatrix}
a & c \\
b & d \\
\end{bmatrix} =
\begin{bmatrix}
ax + by & cx + dy
\end{bmatrix}
\> $$
>
> 이는 행 기준 방식의 정방행렬 $A$를 전치시킨 결과와 동일하다.
>
> $$
\begin{bmatrix}
a & c \\
b & d \\
\end{bmatrix} = 
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix}^T
\> $$
>
> 행 기준 방식을 사용하는 대표적인 사례로는 게임 그래픽스 라이브러리인 다이렉트X(DirectX)가 있으며, 열 기준 방식을 사용하는 게임 그래픽스 라이브러리로는 오픈GL(OpenGL)이 있다.     
유니티(Unity) 엔진은 C# 스크립트에서 열 기준 방식을 사용하고, 언리얼(Unreal) 엔진의 C++ 코드는 행 기준 방식을 사용한다.     
이렇게 그래픽 라이브러리와 애플리케이션마다 행렬을 사용하는 방법은 다르다.      
두 방식 모두 전치연산을 통해 서로 변환할 수 있으므로 방식만 명확하게 이해하고 있다면 응용하는 데 큰 문제는 없다.    
열벡터와 행벡터는 서로 전치 관계에 있기 때문에, 선형 변환 역시 전치 관계의 차이가 있을 뿐이다.
>
> 열 기준 체계에서 설계된 수식을 행 기준에서 가져다 쓰고 싶다면 다음과 같이 전치연산을 적용해 변환하면 된다.
>
> $$(A \cdot \vec{v})^T = \vec{v}^T \cdot A^T$$
>
> $$
(
    \begin{bmatrix}
    a & b \\
    c & d \\
    \end{bmatrix} \cdot
    \begin{bmatrix}
    x \\
    y \\
    \end{bmatrix}
)^T =
\begin{bmatrix}
x \\
y \\
\end{bmatrix}^T \cdot
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix}^T =
\begin{bmatrix}
x & y
\end{bmatrix} \cdot
\begin{bmatrix}
a & c \\
b & d \\
\end{bmatrix}
\> $$
>
> 열 기준 행렬은 행렬의 적용 순서가 오른쪽에서 왼쪽 방향으로 흐르는 역방향으로 진행된다.    
다음 행렬의 곱셈이 열 기준 방식으로 이뤄진다면, 벡터 $v$에 대해 행렬 $A$의 선형 변환이 적용된 후 행렬 $B$의 선형 변환이 적용된다.
>
> $$B \cdot A \cdot \vec{v} = \vec{W}$$
>
> 이와 같은 열 기준 방식의 변환을 행 기준 방식으로 변환하기 위해 위 식을 전치해보면, 계산은 다음과 같이 왼쪽에서 오른쪽의 순방향으로 진행된다.
>
> $$(B \cdot A \cdot \vec{v})^T = (\vec{W})^T$$
> $$\vec{v}^T \cdot A^T \cdot B^T = (\vec{W})^T$$
>
> 이와 같이 열벡터 행렬을 전치한 결과는 행벡터가 된다.  
따라서 행벡터 변환 방식을 사용한다면 행렬의 적용 순서는 왼쪽에서 오른쪽의 순방향으로 진행되므로 이 점을 주의해야 한다.
