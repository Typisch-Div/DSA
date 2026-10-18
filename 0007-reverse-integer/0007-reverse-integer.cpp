class Solution {
public:
    int reverse(int x) {
        int var=x;
        int sum=0;
        while(var!=0){
            int digit=var%10;
            if ((sum > INT_MAX / 10) || (sum < INT_MIN / 10))   return 0;
            var/=10;
            sum=sum*10+digit;
        }

        return sum;

    }
};