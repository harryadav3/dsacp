// this algorithm is used to detect a loop in a linked list
// there are three approaches two solve this
/*
1) Hashing : Traverse the linked list and add each node address to the map. If the current node links to any of the addresses stored in the map then the loop found and true is returned. On the other hand if no node links to an address in the map and NULL is reached then the linked list does not have a loop and false is returned. The time complexity of this method is O(n) since the linked list is traversed once and the space complexity is also O(n) since the hash map is used.
2) Flagging each node : Traverse the linked list and flag the mode such that it can be identified as visited. While traversing if a node is encountered with the flag being visited then the loop is found and true is returned. If the traversal reaches the end of the linked list then no loop exists in the list and false is returned. The time complesity of this method is O(n) and the space complexity is O(1) since no extra space is used.
3) Floyd Cycle Finding Algorithm (Floyd's Hare Tortoise Algorithm):
in this algorithm the slow pointer and fast pointer begin at the first node and keep incrementing slow pointer by one step and fast pointer by two steps respectively. If the fast pointer reaches  null then a loop in the lined list does not exist and false can be returned. If the linked list is in a loop then the slow and fast pointers are incrementing at different speeds in a cycle and will eventually reach a point where they are at the same node in the list. if the fast and slow pointers are at any arbitrary position in the cycle (if they are at the same position then true can be returned). if the slow pointer will be moving by one step in once iteration and the fast pointer will be moving by two steps in the same iteration. eventually the fast pointer is going to cross and surpass the slow pointer before the slow pointer reaches the last node. but eventually theyre are going to meet each other on a same element. Assume a circle and a slow pointer at some point and the fast pointer at some point after the slow pointer. let the distance between the fast pointer and the slow pointer (in clockwise direction) be n. then in the first iteration the slow pointer will increase the distance by 1 and simultaneously the fast pointer will decrease the distance by 2 hence the distance after the first iteration will be n + 1 - 2 = n - 1. so on a single iteration the distance between the fast and slow pointer will be reduced by one. then after n iterations the distance between the two pinters will be n + n - 2n = 0 hence the distance will be 0 and the fast adn slow pointer will reach on the same element.
*/

/*
finding the duplicate number (leetcode)
this question uses the above mentioned floyd cycle algorithm. to find the fist intersection of the fast and slow pointers then a slow pointer is placed at the start of the list and a second slow pointer is placed at the first inctersection both pointers are incremented and till they intersect. this intersection will be the beggining of the loop. this is always going to be the case and is a theorem. why?
proof : let p be the number of the previous nodes before the actual start of the cycle and x be the number of nodes between the second pointer and the start of the cycle. let the length of the cycle be c then the remaining part of the cycle excluding the nodes from the second pointer to the start of the cycle will be c - x since the distance is x between the second pointer to the start of the cycle. before finding the first intersection the fast pointer is going to travel p and the travel the entire loop to surpass the slow pointer and then travel c - x to reach to the first intersection. and the slow pointer on the other hand is going to travel p and then travel c - x to reach to the first intersection

math:
2 (num of iteratuons by slow pointer) = num of iterations of the fast pointer
2 (slow) = p + c + c - x
2 (p + c - x) = p + 2c - x
2p + 2c - 2x = p + 2c - x
p - x = 0
hence p = x
hence  p (the number of the previous nodes before the actual start of the cycle) = x (between the second pointer to the start of the cycle)
that is why when incrementing the two slow pointers they will meet at the start of the cycle of the linked list
*/