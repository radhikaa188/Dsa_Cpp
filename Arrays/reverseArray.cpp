void reverseArray(vector<int> &arr , int m) {
            //two pointer technique
         	int left= m+1;
            int right= arr.size()-1;
            while(left<right){
                int temp= arr[right];;
                arr[right]= arr[left];
                arr[left]= temp;
                left++;
                right--;
            }
            return;
}