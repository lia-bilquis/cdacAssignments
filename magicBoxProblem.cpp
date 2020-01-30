#include<iostream>
using namespace std;
class magic
{
	int cur_col,cur_row,next_col,next_row,m[100][100];
	public:
	      // magic():cur_row(0)
	     //  {
		   //}
	      
		   void calc(int n,int f)
		   {
			   m[0][n/2]=f;
			   int num;
			  int max=(n*n)+f-1;
			  cur_col=n/2;
			  cur_row=0;
			int  num1=f+1;
			   for(num=num1;num<=max;num++)
			   {
				   if((cur_col+1)>(n-1))
				   {
					   next_col=0;
				   }
				   else
				   {
					   next_col=cur_col+1;
				   }
				   if((cur_row-1)<0)
				   {
					   next_row=n-1;
				   }
				   else
				   {
					   next_row=cur_row-1;
				   }
				   if(m[next_row][next_col]>0)
				   {
					   if((cur_row+1)>(n-1))
					   {
						   next_row=0;
					   }
					   else
					   {
						   next_row=cur_row+1;
						   next_col=cur_col;
					   }
				   }
				   cur_row=next_row;
				   cur_col=next_col;
				   m[cur_row][cur_col]=num;
			   }
		   }
			   void display(int n)
			   {
				   int i,j;
				   for(i=0;i<n;i++)
				   {
					   for(j=0;j<n;j++)
					   {
						   cout<<m[i][j]<<"\t";
					   }
					   cout<<"\n";
				   }
			   }
		   };
			   int main()
			   {
				   int n,f;
				   cout<<"enter size";
				   cin>>n;
				   cout<<"\nenter first";
				   cin>>f;
				   magic m;
				   m.calc(n,f);
				   m.display(n);
				   return 0;
			   }

