# [Gold II] Discrete Logarithm is a Joke - 21094 

[문제 링크](https://www.acmicpc.net/problem/21094) 

### 성능 요약

메모리: 2020 KB, 시간: 2712 ms

### 분류

수학, 분할 정복을 이용한 거듭제곱, 임의 정밀도 / 큰 수 연산

### 제출 일자

2026년 04월 23일 13:15:47

### 문제 설명

<p>$M = 10^{18} + 31$ is a prime number. $g = 42$ is a primitive root modulo $M$, which means that $g^{1} \bmod M, g^{2} \bmod M, \ldots, g^{M-1} \bmod M$ are all distinct integers from $[1; M)$. Let's define a function $f(x)$ as the smallest positive integer $p$ such that $g^{p} = x \bmod M$. $f$ is a bijection from $[1; M)$ to $[1; M)$.</p>

<p>Let's then define a sequence of numbers as follows:</p>

<ul>
	<li>$a_{0} = 960\,002\,411\,612\,632\,915$ (you can copy this number from the sample);</li>
	<li>$a_{i + 1} = f(a_{i})$.</li>
</ul>

<p>Given $n$, find $a_{n}$.</p>

### 입력 

 <p>The only line of input contains one integer $n$ ($0 \le n \le 10^{6}$).</p>

### 출력 

 <p>Print $a_{n}$.</p>

