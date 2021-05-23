class BrowserHistory {
public:
    
    struct Page{
        string url;
        struct Page *prev, *next;
        
        Page (string url) {
            this->url = url;
            prev = next = NULL;
        }
    };
    
    
    Page *p, *curr;
    
    BrowserHistory(string homepage) {
        p = new Page(homepage);
        curr = p;
    }
    
    void visit(string url) {
        Page *newPage = new Page(url);
        if (curr->next)
            delete(curr->next);
        curr->next = newPage;
        newPage->prev = curr;
        curr = newPage;
    }
    
    string back(int steps) {
        while (steps-- > 0 && curr->prev) {
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (steps-- > 0 && curr->next) {
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
