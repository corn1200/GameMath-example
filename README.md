
$$
\begin{matrix}
A \cdot \vec{v} = 
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
\end{bmatrix} \\
B \cdot (A \cdot \vec{v}) = 
\begin{bmatrix}
e & f \\
g & h \\
\end{bmatrix} \cdot
\begin{bmatrix}
ax + by \\
cx + by \\
\end{bmatrix} =
\begin{bmatrix}
e(ax + by) + f(cx + dy) \\
g(ax + by) + h(cx + dy) \\
\end{bmatrix}
\end{matrix}
$$

$$B \cdot A =
\begin{bmatrix}
e & f \\
g & h \\
\end{bmatrix} \cdot
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix} =
\begin{bmatrix}
ae + cf & be + df \\
ag + ch & bg + dh \\
\end{bmatrix} \\
(B \cdot A) \cdot \vec{v} = 
\begin{bmatrix}
x(ae + cf) + y(be + df) \\
x(ag + ch) + y(bg + dh) \\
\end{bmatrix}
$$

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
\end{bmatrix}$$
>
> 컴퓨터에서 실제로 행렬을 응용할 때는, 행 기준 행렬을 사용하는 경우도 있다.    
행 기준으로 선형 변환을 수행할 때는 열 기준과 다르게 행렬과 벡터의 위치를 거꾸로 뒤집어서, 다음과 같이 벡터를 앞쪽에 두어야 행렬의 곱셈이 성립된다.
