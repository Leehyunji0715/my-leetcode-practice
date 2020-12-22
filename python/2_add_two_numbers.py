'''
Simple explanation 
    Using linked list, add two linked lists between appropriate digits

What I care
  * Carrier value
  * Number of digits when you have carrier value
'''
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carrier = 0
        result = ListNode(0, None)
        head = result

        while l1 and l2:
            
            if (l1.val < 0 and l2.val >= 0) :
                dsum = l2.val
            elif (l2.val < 0 and l1.val >= 0) :
                dsum = l1.val
            elif (l1.val < 0 and l2.val < 0):
                dsum = 0
            else:
                dsum = l1.val + l2.val
            
            result.val = (dsum + carrier) % 10
            
            carrier = int ( (dsum + carrier)/ 10)
            newNode = ListNode(0, None)

            result.next = newNode
            #result = result.next

            if (l1.next != None) : 
                l1 = l1.next
            elif (l1.val < 0) :
                pass
            else:
                finishNode = ListNode(-1, None)
                l1.next = finishNode
                l1 = l1.next
                
            if (l2.next != None) : 
                l2 = l2.next
            elif (l2.val < 0) :
                pass
            else:
                finishNode = ListNode(-1, None)
                l2.next = finishNode
                l2 = l2.next
                
            if(l1.val < 0 and l2.val < 0):
                if(carrier > 0):
                    result = result.next
                    result.val = carrier
                else: 
                    result.next = None
                break
                
            else:
                result = result.next
        return head
