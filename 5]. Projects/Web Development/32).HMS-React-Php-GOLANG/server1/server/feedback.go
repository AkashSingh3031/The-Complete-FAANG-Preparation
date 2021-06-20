package server

import (
	"encoding/json"
	"net/http"
)
type feedback struct{
	Name string 
	Email string 
	Contact string 
	Suggestion string
}
var feed []feedback
func GetFeedbackEndPoint(w http.ResponseWriter, req *http.Request){
	rows,er:=db.Query("SELECT * FROM `feedback`");
	feed:=[]feedback{};
	if(er==nil){
		var temp feedback
		for rows.Next(){
            rows.Scan(&temp.Name,&temp.Email,&temp.Contact,&temp.Suggestion);
           
            feed=append(feed,temp);
         }
	}
	json.NewEncoder(w).Encode(feed);
}