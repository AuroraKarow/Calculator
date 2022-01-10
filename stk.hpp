STK_BEGIN

template<typename T> class stack
{
protected:
    struct node {node *prev = nullptr; std::unique_ptr<node> next = nullptr /* node *next */; T elem;};
    std::unique_ptr<node> head;
    uint64_t len = 0;
    std::unique_ptr<node> create_node() { return std::make_unique<node>(); }
    T temp;
public:
    uint64_t size() { return len; }
    stack() {}
    stack(stack &src) : len(src.len)
    {
        if(len)
        {
            head = create_node();
            auto src_ptr = src.head.get(),
                temp_ptr = head.get();
            temp_ptr -> elem = src_ptr -> elem;
            for(auto i=1; i<len; ++i)
            {
                (temp_ptr -> next).get() = create_node();
                temp_ptr -> next -> prev = temp_ptr;
                temp_ptr -> next -> elem = src_ptr -> next -> elem;
                temp_ptr = (temp_ptr -> next).get();
                src_ptr = (src_ptr -> next).get();
            }
        }
    }
    stack(stack &&src) : len(std::move(src.len)) { head = std::move(src.head); }
    void operator=(stack &src) {new (this)stack(src);}
    void operator=(stack &&src) {new (this)stack(std::move(src));}
    T top() { return head.get() -> elem; }
    void push(T &src)
    {
        auto temp = create_node();
        temp.get() -> elem = src;
        if(head)
        {
            head.get() -> prev = temp.get();
            temp.get() -> next = std::move(head);
        }
        head = std::move(temp);
        ++ len;
    }
    void push(T &&src)
    {
        auto temp = create_node();
        temp.get() -> elem = std::move(src);
        if(head)
        {
            head.get() -> prev = temp.get();
            temp.get() -> next = std::move(head);
        }
        head = std::move(temp);
        ++ len;
    }
    T &pop()
    {
        if(len)
        {
            temp = std::move(head.get() -> elem);
            head = std::move(head.get() -> next);
            if(head) head.get() -> prev = nullptr;
            -- len;
        }
        return temp;
    }
    friend std::ostream &operator<<(std::ostream &output, stack &src)
    {
        auto tool_ptr = src.head.get();
        for(auto i=0; i<src.len; ++i)
        {
            output << '[' << i << "][" << std::endl << tool_ptr -> elem << std::endl << ']';
            if(i+1 != src.len) output << std::endl;
            tool_ptr = (tool_ptr -> next).get();
        }
        return output;
    }
    // ~stack() {}
};

STK_END