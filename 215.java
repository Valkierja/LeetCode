class Solution {
    public int findKthLargest(int[] nums, int k) {

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int e : nums) {

            pq.offer(e);

            if (pq.size() > k) {
                pq.poll();
            }
        }

        return pq.peek();
    }
}
