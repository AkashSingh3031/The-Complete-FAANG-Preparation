package server

import (
	"encoding/json"
	"fmt"
	"net/http"
)
type admin struct{
	Id string
	Role string
	Name string
	Email string
	Phone string
	Address string
	
}
func GetProfileEndPoint(w http.ResponseWriter, req *http.Request){
	var p admin
	err := json.NewDecoder(req.Body).Decode(&p)
    if err != nil {
        http.Error(w, err.Error(), http.StatusBadRequest)
        return
    }
	rows,er:=db.Query("Select "+p.Role+"_name,email,phone,address FROM `"+p.Role+"` where "+p.Role+"_id="+p.Id);
	if(er==nil){
		for(rows.Next()){
		rows.Scan(&p.Name,&p.Email,&p.Phone,&p.Address);
	}
		json.NewEncoder(w).Encode(p);
		return 
	}else{
		fmt.Println(er);
	}
}
func EditProfileEndPoint(w http.ResponseWriter, req *http.Request){
	var p admin
	json.NewDecoder(req.Body).Decode(&p)
	fmt.Println(p);
	rows,er:=db.Query("update "+p.Role+" set "+p.Role+"_name='"+p.Name+"',email='"+p.Email+"',address='"+p.Address+"',phone='"+p.Phone+"' where +"+p.Role+"_id='"+p.Id+"'");
	if(er==nil){
		_=rows
		fmt.Println("Success")
	}else{
		fmt.Println("Failed");
	}
}