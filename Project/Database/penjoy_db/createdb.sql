CREATE TABLE USER(
	ID   INT              NOT NULL,
   	USERNAME VARCHAR (30) NOT NULL,
   	PASSWORD VARCHAR (30) NOT NULL,
   	EMAIL    VARCHAR (30) NOT NULL,
   	LICENSE  VARCHAR (30) NOT NULL,
   	PAYMENTINFO INTEGER (16) NOT NULL,
   	LOGGEDIN BOOLEAN NOT NULL, 
   	PRIMARY KEY (ID)
);