# Suddenly come up with...
# Make linked list of l1 firstly, then add up l2's values in order 

# But there is time limit excess problem  

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carry = 0
        result = ListNode(0, None)
        head = result

        while l1:
            result.val = l1.val
            
            if(l1.next):
                l1 = l1.next
                result.next = ListNode(0, None)
                result = result.next
            else:
                break
        
        result = head
        while l2:
            dsum = result.val + l2.val + carry
            result.val = dsum % 10
            carry = int(dsum/10)

            if(l2.next):
                l2 = l2.next
                if(result.next):
                    result = result.next
                else:
                    result.next = ListNode(0, None)
                    result = result.next
            elif (carry):
                if(result.next):
                    result.next.val = result.next.val + carry
                else:
                    result.next = ListNode(carry, None)
            else:
                break
        return head

