/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//! Another method of doing so is by joining all the linked list and then finally putting it for merge sort.

//!Approach - 1
//* Using priority Queues.

class Solution
{
public:
    class cmp
    {
    public:
        bool operator()(const ListNode *l1, const ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        //! We will be storing actual nodes in our priority_queue not the copies of it.
        //! push_back often creates Duplicates.Therefore we will use emplace_back function to store real objects.
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        int k = lists.size();

        for (int i = 0; i < k; i++)
        {
            //! condition prevents from adding NULL as values and thus causing runtime error in while loop
            //! It prevents TestCase-3 i.e [[]]
             
            if (lists[i] == NULL)
                continue;
            pq.push(lists[i]);
        }

        ListNode *ptr = new ListNode(-1);
        ListNode *dummy = ptr;

        while (!pq.empty())
        {
            ListNode *curr = pq.top();
            pq.pop();
            if (curr->next != NULL)
                pq.push(curr->next);
            ptr->next = curr;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};


//!Approach - 2
//* Using merge Sort.