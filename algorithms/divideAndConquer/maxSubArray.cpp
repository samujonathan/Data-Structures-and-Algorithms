#include <iostream>
#include <vector>

using namespace std;

int max3( int a, int b, int c )
{
    return a > b ? a > c ? a : c : b > c ? b : c;
}

int maxSumRec( const vector<int> & a, int left, int right )
{
	if( left == right )  {
		if( a[ left ] > 0 ) {
            return a[ left ];
		} else {
            return 0;
		}
	}

    int center = ( left + right ) / 2;
    int maxLeftSum  = maxSumRec( a, left, center );
    int maxRightSum = maxSumRec( a, center + 1, right );

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for( int i = center; i >= left; --i )
    {
        leftBorderSum += a[ i ];
        if( leftBorderSum > maxLeftBorderSum )
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for( int j = center + 1; j <= right; ++j )
    {
        rightBorderSum += a[ j ];
        if( rightBorderSum > maxRightBorderSum )
            maxRightBorderSum = rightBorderSum;
    }

    return max3( maxLeftSum, maxRightSum,
                    maxLeftBorderSum + maxRightBorderSum );
}

int maxSubSum3( const vector<int> & a )
{
    return maxSumRec( a, 0, a.size( ) - 1 );

}

int main() {
	int n;
	vector<int> a;

	cout << "Number of elements:" << endl;
	cin>>n;
	cout << "Enter elements:" << endl;
	int digit;
	for (int i=0;i<n;++i)
	{
		cin>>digit;
		a.push_back(digit);
	}	
	int maxSum = maxSubSum3(a);
	cout << "Maximum sum of subarray: " << maxSum << endl;
}
