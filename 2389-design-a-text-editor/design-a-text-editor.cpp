class Node {
public:
    char ch;
    Node *prev, *next;
    Node(char c) {
        ch = c;
        prev = next = nullptr;
    }
};
class TextEditor {
public:
    Node *head;
    Node *cursor;
    TextEditor() {
        head = new Node('#');      // dummy node
        cursor = head;             // cursor initially at beginning
    }
    void addText(string text) {
        for(char c : text) {
            Node *node = new Node(c);
            node->next = cursor->next;
            node->prev = cursor;
            if(cursor->next)
                cursor->next->prev = node;
            cursor->next = node;
            cursor = node;         // cursor moves after inserted character
        }
    }
    int deleteText(int k) {
        int cnt = 0;
        while(cursor != head && k--) {
            Node *del = cursor;
            cursor = cursor->prev;
            cursor->next = del->next;
            if(del->next)
                del->next->prev = cursor;
            delete del;
            cnt++;
        }
        return cnt;
    }
    string cursorLeft(int k) {
        while(cursor != head && k--)
            cursor = cursor->prev;
        return last10();
    }
    string cursorRight(int k) {
        while(cursor->next && k--)
            cursor = cursor->next;
        return last10();
    }
private:
    string last10() {
        string ans;
        Node *temp = cursor;
        while(temp != head && ans.size() < 10) {
            ans += temp->ch;
            temp = temp->prev;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */