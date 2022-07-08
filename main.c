#include <stdlib.h>
#include <stdio.h>



int main (){
            int i, j, wierszA, n, A[i][j];
            printf("\n\tWprowadz ilosc wierszy macierzy A: ");
            scanf("%d", &m);
            printf("\n\tWprowadz ilosc kolumn macierzy A: ");
            scanf("%d", &n);
            for (i=0; i<m; ++i){
                        for (j=0; j<n; ++j){
                           A[i][j];
                        }
                        j=0;
            }
            printf("\n\tWprowadz elementy macierzy A:\n");
            for(i = 0; i < m; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			printf("\tWprowadz elementy a%d%d: ", i + 1, j + 1);
			scanf("\t%d", &A[i][j]);
		}
	}
	printf("\n\tWyprowadzona macierz:\n\t");
	for(i = 0; i < m; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			printf("%d  ", A[i][j]);
			if(j == n - 1)
				printf("\n\n\t");
		}
	}


return (0);
}
