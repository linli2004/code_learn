/*
如何写记忆化搜索
方法一

    把这道题的 dp 状态和方程写出来
    根据它们写出 dfs 函数
    添加记忆化数组

    方法二

    写出这道题的暴搜程序（最好是 dfs）
    将这个 dfs 改成「无需外部变量」的 dfs
    添加记忆化数组
*/


#include <iostream>
using namespace std;
int arr[103];
int men[103];

int dfs(int i){
    if(men[i]!=-1) return men[i];
    int ret=1;
    for(int j=1;j<i;j++){
        if(arr[j]<arr[i]){
            ret=max(ret,dfs(j)+1);
        }
    }
    return men[i]=ret;
}

int main(){
    return 0;
}