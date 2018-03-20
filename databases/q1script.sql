/*Thomas Griffin A1 question 1 script*/
CREATE TABLE Product(
	ProductId int 
	CONSTRAINT PK_Prod PRIMARY KEY,
	ProductDesc VARCHAR(200)
);

CREATE TABLE Item(
	ItemNum int NOT NULL, 
	ItemDesc VARCHAR(200),
	CONSTRAINT PK_Item PRIMARY KEY(ItemNum)
);

CREATE TABLE Receipt(
	ReceiptNum int NOT NULL,
	SalesDate DATE,
	CONSTRAINT PK_Rec PRIMARY KEY(ReceiptNum)
);

CREATE TABLE Sold(
	ReceiptNum int,
	ItemNum int, 
	QuantitySold int,
	CONSTRAINT PK_Sold PRIMARY KEY(ReceiptNum, ItemNum),
	CONSTRAINT CH_Sold CHECK(QuantitySold >= 0)
);

CREATE TABLE Used(
	ProductId int,
	ItemNum int,
	QuantityUsed int,
	CONSTRAINT PK_Used PRIMARY KEY(ProductID, ItemNum),
	CONSTRAINT CH_Used CHECK(QuantityUsed >= 0)
	);

