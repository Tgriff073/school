struct ZipInfo
 {
  string zip;
  string state;
  PoBox po;
  char pc;
  string city;
  void init(ZipInfo&);
  void work(ZipInfo&,int, int&);
  };//end of struct
