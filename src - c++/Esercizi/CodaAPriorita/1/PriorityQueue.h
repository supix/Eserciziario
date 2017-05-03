typedef int TElem;

struct Record;
typedef Record* PRec;

class PriorityQueue {
private:
  PRec head;
  PRec tail; //puntatore alla coda
  PRec tail_h; //puntatore alla coda della sottosequenza ad alta priorità
  void Push(const TElem& e); //classico Push in coda
public:
  PriorityQueue();
  ~PriorityQueue();
  
  void PushLow(const TElem& e);
  void PushHigh(const TElem& e);
  TElem Pop();
  void Clear();
  bool Empty() const;
};
