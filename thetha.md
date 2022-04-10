 
### Counterexample

The function $g(n) = n+1$ is clearly in $\mathcal{O}(f)$ and $\Omega(f)$ for $f(n) = n$, but doesn't satisfy the equation $g(n)=c \cdot f(n)$.


### Correct compact definition of Theta(f)


$$
\begin{equation*}
\Theta(f) = \{  g: \mathbb{N} \rightarrow \mathbb{R}\ |\ \exists a>0,\ \exists b>0,\ \exists n_0 \in \mathbb{N}: \forall n \geq n_0: 0 \leq a \cdot f(n) \leq g(n) \leq b \cdot f(n)\}.
\end{equation*}
$$
  
But this can be done even more compact.
If the definition holds for an $a$ and $b$, we can find a $c$ such that $b\leq c$ and $\frac1c \leq a$. Using this $c$ we can give a more compact definition

$$
\begin{equation*}
\Theta(f) = \{  g: \N \rightarrow \R\ |\ \exists c>0,\ \exists n_0 \in \N: \forall n \geq n_0: 0 \leq \frac1c \cdot f(n)\leq g(n) \leq c \cdot f(n)\}.
\end{equation*}
$$
