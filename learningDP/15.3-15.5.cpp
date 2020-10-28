#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
//15.3

//发掘最优子结构性质中，以下通用模式
//做出选择-假定知道最优解的选择->确定选择产生子问题，以及如何最好的刻画子问题空间(保持子问题尽可能简单，只在必要时拓展)
//证明：构成原问题最优解组成部分，每个子问题的解就是本身的最优解

//最优子结构的不同体现在两个方面
//1.原问题最优解中涉及多少子问题
//2.确定最优解使用哪些子问题，需要考察多少种选择

//判断最优子结构例子：有向图的无权最长路径和无权最短路径

//重叠子问题
//子问题空间足够"小" 即递归算法反复求解相同子问题，而不是一直生成新的子问题
//相对的，适合用分支方法求解的问题通常在递归的每一步都生成全新子问题

//15.4
//最长公共子序列(LCS问题)

//分析得状态转移方程 c[i,j]表示Xi和Yj的LCS长度
/*              0 , i=0||j=0
        c[i,j]= c[i-1,j-1]+1 i>0,j>0,xi=yj
                max(c[i,j-1],c[i-1,j]) i>0,j>0,xi!=yj

*/
//计算LCS长度代码
vector<vector<size_t>> LCSlength(string X,string Y){
    size_t LenX=X.size(),LenY=Y.size();
    vector<vector<size_t>> c(LenX+1,vector<size_t>(LenY+1,0));//保存数值
    vector<vector<char>> b(LenX+1,vector<char>(LenY+1));//保存解本身 7:↖
    for(size_t i=1;i<=LenX;++i){
        for(size_t j=1;j<=LenY;++j){
            if(X.at(i)==Y.at(j)){
                c.at(i).at(j)=c.at(i-1).at(j-1)+1;
                b.at(i).at(j)='↖';
            }
            else if(c[i-1,j]>=c[i,j-1]){
                c.at(i).at(j)=c.at(i-1).at(j);
                b.at(i).at(j)='↑';
            }
            else {
                c.at(i).at(j)=c.at(i).at(j-1);
                b.at(i).at(j)='←';
            }
        }
    }
    return c;
}
//步骤4 构造LCS (using 2D vector b forehead)
//空间复杂度优化 1.(2*n)  2. n+1(1 for 对角元素)

//15.5 最优二叉搜索树
//步骤1 最优二叉搜索树的结构 
//key:关键字，伪关键字，概率
//步骤2 确认状态转移方程
/*
    e[i,j]:包含关键字ki,...,kj最优二叉搜索树进行一次搜索的期望代价
    最终目标:e[1,n]
    e[i,j]=qi-1 if j==i-1
            min(e[i,r-1]+r[r+1,j]+w[i][j]) (r from i to j) i<=j
*/
//步骤3 计算代码
/*
vector<vector<double>> OptimalBST(vector<double> p,vector<double> q,size_t n){
    vector<vector<double>> e(n+2,vector<double>(n+1,0));
    vector<vector<double>> w(n+2,vector<double>(n+1,0));//save add to calculate w(i,j)
    vector<vector<double>> root(n+1,vector<double>(n+1,0));//record the root of subtree consist of ki,...kj
    for(size_t i =1;i<=n+1;++i){
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(size_t l=1;l<=n;++l){
        for(size_t i=1;i<=n-l+1;++i){
            size_t j=i+l-1;
            e[i][j]=INT_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(size_t r=i;r<=j;++r){
                double tem=e[i][r-1]+e[r+1][j]+w[i][j];
                if(tem<e[i][j]){
                    e[i][j]=tem;
                    root[i][j]=r;
                }//有趣的事 当不要求构造解时 我们只需要求最值即可 省去判断条件...
            }
        }
    }
    return e;
}

*/
//理论知识到此已经基本结束...
//some example execrises
//15-2 Longest palindrome subsequence (Leetcode 516)
//15-5 Edit Distance(Leetcode 60)

//补充:背包九讲
