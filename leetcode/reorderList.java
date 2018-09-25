/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        
        if(head==null || head.next == null || head.next.next == null){
            return;
        }
    
        ListNode slowPointerPrev =null;
        ListNode slowPointer = head;
        ListNode fastPointer = head;
        
        while(fastPointer!=null && fastPointer.next!=null){
            slowPointerPrev = slowPointer;
            slowPointer= slowPointer.next;
            fastPointer = fastPointer.next.next;
        }
        
        slowPointerPrev.next = null;
        slowPointer = reverseList(slowPointer);
        fastPointer = head;
        
        while(fastPointer!=null && slowPointer!=null){
            ListNode temp1 = fastPointer.next;
            ListNode temp2 = slowPointer.next;
            
            fastPointer.next = slowPointer;
            slowPointer.next = temp1==null? slowPointer.next : temp1 ;
            fastPointer = temp1;
            slowPointer = temp2;
        }
        
        
        
    }
    
   
    
    
    
    public ListNode reverseList(ListNode head){
        
        if(head==null || head.next==null){
            return null;
        }
        ListNode p = null,c = head,n = head.next;
        
        while(n!=null){
            
            c.next = p;
            p = c;
            c = n;
            n = n.next;
        }
        
        c.next = p;
        
        return c;
    }
}
