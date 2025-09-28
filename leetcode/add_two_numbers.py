# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        val1 = ""
        val2 = ""
        curr = l1

        while (curr != None):
            val1 += str(curr.val)
            print(curr.val)
            curr = curr.next

        curr = l2
        while (curr != None):
            val2 += str(curr.val)
            curr = curr.next

        print(val1, val2)
        val1 = val1[::-1]
        val2 = val2[::-1]
        
        res = map(int, list(str(int(str(int(val1) + int(val2))))[::-1]))
        

        tail = head = ListNode(res[0])
        for x in res[1:]:
            tail.next = ListNode(x) # Create and add another node
            tail = tail.next # Move the tail pointer

        return head