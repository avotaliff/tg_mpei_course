//https://leetcode.com/problems/split-linked-list-in-parts/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> v;
    //если список пуст, то он поделится на одинаковые пустые части    
        if (root == NULL){ 
            while (k != 0){
                v.push_back(NULL);
                k--; 
            }
            return v;
        }
        else{
            ListNode* root1 = root;
            int col=0; //количество элементов списка
            while (root1 != NULL) {
                col++;
                root1=root1->next;     
            }
            root1=root;
            while (col != 0){
            //функция ceil находит нимимальное число (х с N), которое больше или равно аргументу
                int length = ceil(col*1.0/k); //длина "подсписка"
                
                ListNode*l1 = root1; //для выделения "подсписка" из списка
                ListNode*l1_h = root1; //указатель на начало "подсписка"
                
                for (int i=0; i<length; i++){
                    l1 = root1;
                    root1=root1->next;
                }
                l1->next = NULL;
                v.push_back(l1_h);
                col = col - length;
                k--;    
            }
           while (k != 0){ //подсписки уже выделены, а ячейки остались, заполним их нуллами
               v.push_back(NULL);
               k--;
           } 
        }
    return v;
    }
};
