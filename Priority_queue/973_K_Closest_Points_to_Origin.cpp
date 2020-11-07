//We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
//
//(Here, the distance between two points on a plane is the Euclidean distance.)
//
//You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
//
// 
//
//Example 1:
//
//Input: points = [[1,3],[-2,2]], K = 1
//Output: [[-2,2]]
//Explanation: 
//The distance between (1, 3) and the origin is sqrt(10).
//The distance between (-2, 2) and the origin is sqrt(8).
//Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
//We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
//Example 2:
//
//Input: points = [[3,3],[5,-1],[-2,4]], K = 2
//Output: [[3,3],[-2,4]]
//(The answer [[-2,4],[3,3]] would also be accepted.)
// 
//
//Note:
//
//1 <= K <= points.length <= 10000
//-10000 < points[i][0] < 10000
//-10000 < points[i][1] < 10000


//push() adds a copy of an already constructed object into the queue as a parameter, it takes an object of the queue's element type.
//
//emplace() constructs a new object in - place at the end of the queue.It takes as parameters the parameters that the queue's element types constructor takes.
//
//If your usage pattern is one where you create a new object and add it to the container, you shortcut a few steps(creation of a temporary objectand copying it) by using emplace().
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < points.size(); i++) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            if (q.size() > K) q.pop();  //reduce sorted time to nlogk
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};