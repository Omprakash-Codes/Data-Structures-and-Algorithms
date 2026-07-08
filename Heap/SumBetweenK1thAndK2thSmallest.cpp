// Problem: Sum of Elements Between K1'th and K2'th Smallest Elements
// Approach:
// Max Heap + Kth Smallest Element
// Description:
// Find the K1'th and K2'th smallest elements
// using a max heap of size K. Then calculate
// the sum of all elements strictly lying
// between these two values.
// Time Complexity:
// O(N log K)
// Space Complexity:
// O(K)
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
    // Your code here
    long long sum1=0;
    priority_queue<long long>pq1(A,A+K1);
    for(long long i=0;i<K1;i++){
        sum1+=A[i];
    }
    for(long long i=K1;i<N;i++){
        if(A[i]<pq1.top()){
            sum1-=pq1.top();
            pq1.pop();
            pq1.push(A[i]);
            sum1+=A[i];
        }
    }
    long long sum2=0;
    priority_queue<long long>pq2(A,A+K2);
    for(long long i=0;i<K2;i++){
        sum2+=A[i];
    }
    for(long long i=K2;i<N;i++){
        if(A[i]<pq2.top()){
            sum2-=pq2.top();
            pq2.pop();
            pq2.push(A[i]);
            sum2+=A[i];
        }
    }
    return sum2-sum1-pq2.top();
}
