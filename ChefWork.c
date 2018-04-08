/*
There are N workers; each worker is of one of the following three types:

A translator translates some text from Chef's language to another langague.
An author writes some text in Chef's language.
An author-translator can both write a text in Chef's language and translate it to another language.
Chef wants to have some text written and translated into some language (different from Chef's language). Chef can't do either of those tasks, but he can hire workers. For each i (1≤i≤N), if he hires the i-th worker, he must pay that worker ci coins.

Help Chef find the minimum total number of coins he needs to pay to have a text written and translated. It is guaranteed that it is possible to write and translate a text.

Input
The first line of the input contains a single integer N denoting the number of workers.
The second line contins N space-separated integers c1,c2,...,cN denoting the numbers of coins Chef has to pay each hired worker.
The third line contains N space-separated integers t1,t2,...,tN denoting the types of workers. For each valid i, the i-th worker is a translator if ti=1, an author if ti=2 or an author-translator if ti=3.
Output
Print a single line containing one integer — the minimum number of coins Chef has to pay.

Constraints
1≤N≤1,000
1≤ci≤100,000 for each valid i
1≤ti≤3 for each valid i
Subtasks
Subtask #1 (15 points): all workers are author-translators

Subtask #2 (85 points): original constraints

Example Input
5
1 3 4 6 8 
1 2 1 2 3
Example Output
4
Explanation
Chef can hire 2 workers: worker 1, who is a translator, and worker 2, who is an author. In total, he pays them 1+3=4 coins


*/


#include<stdio.h>
int find_min(int *a,int *b,int n){
	int x=100001,y=100001,z=100001;
	for(int i=0;i<n;i++){
		if(b[i]==1){
			if(a[i]<x)
				x=a[i];
		}
		else if(b[i]==2){
			if(a[i]<y)
				y=a[i];
		}
		else if(b[i]==3){
			if(a[i]<z)
				z=a[i];
		}
		else
			continue;
}
if((x+y)>z)
	return z;
return x+y;
}
int main(){
	int n;
	scanf("%d",&n);
	int co[n];
	for(int i=0;i<n;i++)
		scanf("%d",&co[i]);
	int ty[n];
	for(int i=0;i<n;i++)
		scanf("%d",&ty[i]);
	printf("%d\n",find_min(co,ty,n));
	return 0;	
	} 
