    A
   / \
  B   C


pre - order(VLR)：當CurrentNode移動到A時，會先對A進行Visiting，接著前往left child進行Visiting，再前往right child進行Visiting。(若child指向NULL則忽略。)
A-B-C

in - order(LVR)：當CurrentNode移動到A時，會先對A的left child(B)進行Visiting，接著回到A進行Visiting，再前往right child(C)進行Visiting。(若child指向NULL則忽略。)
B-A-C
***in order的遍歷用stack先存最左下的node,再一個一個pop出來看有沒有右邊的分支 **see 173

post - order(LRV)：當CurrentNode移動到A時，會先對A的left child(B)進行Visiting，再前往right child(C)進行Visiting，接著回到A進行Visiting。(若child指向NULL則忽略。)
B-C-A

Level - order是照著「level由小到大」的順序，由上而下，並在同一個level「由左至右」依序Visiting每個node。
A-B-C