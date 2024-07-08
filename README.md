# עצים - STL, Templates, and Iterators
עץ הוא גרף קשיר ללא מעגלים. באלגוריתמים 1 למדתם על אלגוריתמים לסריקה של גרף (כמו BFS ו-DFS).
במטלה הזאת אתם תממשו קונטיינר המייצג עץ k-ארי (עץ k-ארי הוא עץ שבו לכל קודקוד יש לכל היותר k ילדים. למשל, עץ בינארי הוא עץ 2-ארי.) גנרי שמכיל מפתחות מכל סוג (למשל מספרים, מחרוזות ומחלקות). 
המצב הדיפולטיבי של העץ הוא עץ בינארי (כלומר k=2). בשלב היצירה של הקונטיינר עליכם יהיה לציין את הסוג של המפתחות שהוא מכיל ואת מספר הילדים המקסימלי שיכול להיות לכל קודקוד. אם המספר הזה לא צוין, העץ יהיה עץ בינארי.
עליכם לממש את האיטרטורים הבאים:
1. איטרטור Pre-Order - איטרטור הסורק את העץ בצורה הבאה: צומת נוכחית -> תת עץ שמאלי -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
2. איטרטור Post-Order - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> תת עץ ימני -> צומת נוכחית (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
3. איטרטור In-Order  - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> צומת נוכחית -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
5. איטרטור BFS - סריקת העץ לרוחב (משמאלי לימין) (עובד על עץ כללי).
6. איטרטור DFS - סריקת העץ בעזרת אלגוריתם DFS (עובד על עץ כללי).
7. איטרטור Heap - הפיכת עץ בינארי לערימת מינימום, לקריאה נוספת: https://he.wikipedia.org/wiki/%D7%A2%D7%A8%D7%99%D7%9E%D7%94_%D7%91%D7%99%D7%A0%D7%90%D7%A8%D7%99%D7%AA (פה אתם יכולים באלגוריתמים של הספרייה התקנית).

שם הקונטיינר צריך להיות `tree`. יש להגדיר את המתודות הבאות:
1. המתודה `add_root` - הוספת השורש של העץ. המתודה מקבלת צומת כלשהו ושמה אותו בשורש העץ.
2. המתודה `add_sub_node` - הוספת ילד לאב. המתודה מקבלת צומת בעץ וצומת כלשהו ויוצרת בן עבור אותו צומת.
3. המתודות `begin_pre_order`, `end_pre_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Pre-Order.
4. המתודות `begin_post_order`, `end_post_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Post-Order.
5. המתודות `begin_in_order`, `end_in_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת In-Order.
6. המתודות `begin_bfs_scan`, `end_bfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם BFS.
7. המתודות `begin_dfs_scan`, `end_dfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם DFS.
8. המתודה `myHeap`. המתודה הופכת עץ בינארי לערימת מינימום וחזירה איטרטורים עבור הערימה שהתקבלה.
9. יש לממש מפרק (Destructor) המוחק את כל העץ.
10. פונקציית הדפסה. ההדפסה תתבצע בעזרת GUI. עליכם ליצור ממשק שמדפיס את העץ על המסך בצורה הגיוניות לשיקולכם.

יש לכתוב קובץ main שבו אתם מדגימים את אופן פעולת התוכנית. עליכם לכתוב מחלקה בשם Complex (המייצגת מספרים מדומים) ולהשתמש גם בה כדי להדגים את הקוד שלכם. (למדתם על המחלקה הזאת בתרגולים).

בנוסף, עליכם לכתוב בדיקות מקיפות לקוד שלכם.

כדי להשתמש ב-GUI אתם יכולים להיעזר בספרייה הבאה: https://wiki.qt.io/Qt_for_Beginners ובמדריך: https://www.youtube.com/watch?v=cXojtB8vS2E. כמובן שאתם יכולים להשתמש בכל ספרייה שאתם רוצים.

יש להוסיף קובץ Makefile כאשר הפקודה `make tree` מריצה את התוכנית הראשית שלכם. עליכם להגיש קובץ `README` המסביר את ההיררכיה של המחלקות ובאילו ספריות השתמשתם.
כמו כן, עליכם לכתוב בתחילת כל קובץ את המייל שלכם. אי עמידה בהנחיות תגרור הפחתה בציון.

בהצלחה!
   
# Tree Project

## Overview
This project implements a generic k-ary tree container in C++. The tree supports various traversal methods including Pre-Order, Post-Order, In-Order (for binary trees), BFS, and DFS. Additionally, it includes a method to convert a binary tree into a min-heap.

## Structure
- `node`: Template class representing a node in the tree.
- `tree`: Template class representing the tree, containing methods to add nodes and traverse the tree.
- `Complex`: Class representing complex numbers, used for demonstration.
- `Demo.cpp`: Main file demonstrating the usage of the tree.
- `tree.hpp`: Implementation of the Tree class.
- `Makefile`: File to build the project.

## Dependencies
- SFML for GUI representation.

## Building and Running
To build and run the project, use the following commands:

```bash
make
./bin/demo