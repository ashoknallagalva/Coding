/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode A, int B, int C) {
        
        if(A==null || A.next == null || B==C){
            return A;
        }
        
        ListNode bNode = A;
        ListNode bPrev = null;
        ListNode cNode, cNext;
        ListNode temp = A;
        
      int i=1;
      while(i != B){
          bPrev = bNode;
          bNode =bNode.next;
          i++;
      }
       
      cNode = bNode;
      while(i!=C){
          cNode = cNode.next;
          i++;
      }
       
      cNext = cNode.next;
      cNode.next = null;
       
      temp = reverse(bNode);
       
       if(bPrev!=null){
           bPrev.next = temp;
       } else {
           A = temp;
       }
       bNode.next = cNext;
       
      return A;

    }

    
    public ListNode reverse(ListNode A){
        
        if(A==null || A.next==null){
            return A;
        }
        ListNode p = null;
        ListNode c = A;
        ListNode n = A.next;
        
        while(n != null){
            c.next = p;
            p=c;
            c=n;
            n=n.next;
        }
        c.next = p;
        
        return c;
    }
}

