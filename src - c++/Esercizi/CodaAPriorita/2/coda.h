typedef int TElem;

struct Record;
typedef Record* PRec;

class Coda {
private:
  PRec head;
  PRec tail;
  int nelem;
public:
  Coda();
  ~Coda();
  
  void Push(const TElem& e);
  TElem Top() const;
  TElem Pop();
  void Svuota();
  int Count() const;
  bool Empty() const;
};

