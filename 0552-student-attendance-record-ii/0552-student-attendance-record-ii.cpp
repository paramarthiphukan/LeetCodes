class Solution {
public:
	int checkRecord(int n) {
		int MOD=1e9+7;
		vector<long> XX(n+1);
		vector<long> XL(n+1);
		vector<long> XLL(n+1);
		vector<long> A(n+1);
		vector<long> AL(n+1);
		vector<long> ALL(n+1);
		XX[0]=1;
		for(int i=1;i<=n;i++){
			XLL[i]=XL[i-1];
			XL[i]=XX[i-1];
			XX[i]=(XX[i-1]+XL[i-1]+XLL[i-1])%MOD;
			A[i]=(XLL[i-1]+XL[i-1]+XX[i-1]+AL[i-1]+ALL[i-1]+A[i-1])%MOD;
			AL[i]=A[i-1];
			ALL[i]=AL[i-1];
		}
		return (XX.back()+XL.back()+XLL.back()+A.back()+AL.back()+ALL.back())%MOD;
	}
};