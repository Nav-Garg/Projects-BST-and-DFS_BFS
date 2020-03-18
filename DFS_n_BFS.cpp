/*Project- Breadth First Search(BFS) and Depth First Search(DFS)*/

#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class RandomNumber
{
	int low,high;
	
	public:
	RandomNumber(int h=10,int l=0):low(l),high(h)
	{
		srand(time(0));
	}
	
	int operator()(){
		return rand()%(high-low)+low;
	}
};

const int MAX=40;
class Graph
{
	int nv;
	vector <vector<int> > adjM;
	vector<bool> visited;
	
	public:
		Graph(int v=10):nv(v),adjM(v),visited(v)  {}
		void genGraph()
		{
			RandomNumber r(2,0);
			for(int i=0;i<nv;i++)
			{
				visited[i]=false;
				for(int j=0;j<nv;j++)
				{
					adjM[i].push_back(r());
				}
			}
		}
		
		void printGraph()
		{
			for(int i=0;i<nv;i++)
			{
				cout<<i<<"  ->   ";
				for(int j=0;j<nv;j++)
				{
					cout<<adjM[i][j]<<"   ";
				}
				cout<<"\n";
			}
		}
		
		void DFS(int s=3)
		{
			stack<int> stk;
			stk.push(s);
			visited[s]=true;
			cout<<"\nDFS sequence::.............\n";
			while(!stk.empty())
			{
				int t=stk.top();
				stk.pop();
				cout<<t<<"  ";
				for(int i=0;i<nv;i++)
				{
					if(adjM[t][i])
					{
						if(!(visited[i]))
						{
							visited[i]=true;
							stk.push(i);
						}
					}
				}
			}
		}
		
		void BFS(int s=3)
		{
			queue<int> q;
			q.push(s);
			visited[s]=true;
			cout<<"\nBFS sequence::........\n";
			while(!q.empty())
			{
				int s=q.front();
				cout<<s<<"  ";
				q.pop();
				for(int i=0;i<nv;i++)
				{
					if(adjM[s][i])
					{
						if(!(visited[i]))
						{
							visited[i]=true;
							q.push(i);
						}
					}
				}
			}
		}
};

int main()
{
	Graph g(7);
	//g.genGraph();
	//g.printGraph();
	int choice;
	while(1)
	{
		cout<<"\n\nOPERATIONS:\n1.DFS\n2.BFS\n3.Exit\nENTER CHOICE:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				//Graph g(7);
				g.genGraph();
				g.printGraph();
				g.DFS(4);
				break;
			case 2:
				//Graph g(7);
				g.genGraph();
				g.printGraph();
				g.BFS(5);
				break;
			case 3:
				exit(1);
			default:
				cout<<"\nWrong option entered\n";
		}
	
	}
	return 0;
}

