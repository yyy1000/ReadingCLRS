//this cpp file is for recording my learning DP's problem and note
//made by elfgum
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
/*
DP:最优化问题，一个最优解

1.刻画一个最优解的结构特征
2.递归地定义最优解的值
3.计算最优解的值，通常：自底向上的方法
//(当不需要解本身时，可忽略)4.利用计算出的信息构造一个最优解

*/

//15.1钢条切割
/*
问题分析：
一般地，对于长度rn，我们可以用更短地钢条切割效益描述
rn=max(pn,r1+rn-1,r2+rn-2,...,rn-1+r1)
满足：最优子结构：问题地最优解由相关子问题的最优解组合而成，而这些子问题可以独立求解
*/

//递归实现
/*
template<typename T>
int CutRod(T p,int n){
    if(n==0) return 0;
    int res=INT32_MIN;
    for(int i=0;i<n;++i){
        res=max(res,p[i]+CutRod(p,n-i-1));
    }
    return res;
}
int main(){
    vector<int> dp={1,5,8,9,10,17,17,20,24,30};
    int res=CutRod(dp,40);
    cout<<res<<endl;
    system("pause");
    return 0;
}
*/

/*
此函数的效率极低
reason：CutRod反复用相同参数值对自身进行递归调用，即：反复求解相同子问题
渐进时间复杂度，见CLRS P207
*/

/*
两种等价的动态规划实现方法
1.带备忘录的自顶向下法
2.自底向上法
*/

//1
/*
const int n = 7;
vector<int> dp(n+1,INT_MIN);
int MemorizedCutRod(vector<int> p, int n) {
    int tem = INT_MIN;
    if (n == 0) tem = 0;
    else if (dp[n] >= 0) return dp[n];
    for (int i = 1; i <=n; ++i)
        tem =max(tem, p[i-1] + MemorizedCutRod(p, n - i));
    dp[n] = tem;
    return tem;
}
int main() {
    vector<int> money = { 1,5,8,9,10,17,17,20,24,30 };
    int res = MemorizedCutRod(money, n);
    cout << res << endl;
    //for (int i = 0; i < n; ++i) cout << dp[i] << endl;
    system("pause");
    return 0;
}
//注：此处也可不用全局变量 修改方式：向函数中传参
*/

//2
/*
int BottomUpCutRod(vector<int> p,int n){
    vector<int> r(n+1,0);
    r[0]=0;
    for(int i=1;i<=n;++i){
        int res=INT_MIN;
        for(int j=1;j<=i;++j)
            res=max(res,p[j-1]+r[i-j]);
        r[i]=res;
    }
    return r[n];
}

int main() {
    vector<int> money = { 1,5,8,9,10,17,17,20,24,30 };
    int res = BottomUpCutRod(money, 8);
    cout << res << endl;
    system("pause");
    return 0;
}
*/
//extension:能给出切割方式

//15.2 矩阵链乘法
//问题分析
//步骤1:最优括号化方案的结构特征
//步骤2:递归求解方案
//递归基:当链长度为1时，不需要任何计算，代价为0
//状态转移方程:m[i,j]=0, i=j
//                   min(m[i,k]+m[k+1,j]+pi-1*pk*pj), i<j
//注意到，递归算法会在递归调用树的不同分支中多次遇到同一个子问题
//这种子问题重叠的性质是应用动态规划的一个标识(另一个：最优子结构)

//步骤3 计算最优代价,自底向上算法如下
/*
vector<vector<int>> MatrixChainOrder(vector<int> p){
    size_t n=p.size()-1;
    vector<vector<int>> m(n,vector(n,0));//save for prices
    vector<vector<int>> s(n-1,vector(n,0));//save for solutions
    for(int l=2;l<=n;++l){//l is the chain length
        for(int i=1;i<=n-l+1;++i){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j-1;++j){
                int q=m[i][k]+m[k+1][j]+p.at(i-1)*p.at(k)*p.at(j);
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return m;
}*/

//步骤4 构造最优解
//省略 见P215
