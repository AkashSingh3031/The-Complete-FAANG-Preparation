package server

import (
	"encoding/json"
	"fmt"
	"net/http"
)
type Auth struct{
	Email string 
	Password string
	Role string
}
type User struct{
	User_id string
	Name string
}
type Token struct {
	Role        string `json:"role"`
	Email       string `json:"email"`
	TokenString string `json:"token"`
}

type Error struct {
	IsError bool   `json:"isError"`
	Message string `json:"message"`
}

func LoginEndPoint(w http.ResponseWriter, req *http.Request){
	var p Auth
	var temp User;
	var auth bool;
    err := json.NewDecoder(req.Body).Decode(&p)
    if err != nil {
        http.Error(w, err.Error(), http.StatusBadRequest)
        return
    }

	rows,er:=db.Query("SELECT "+p.Role+"_id,"+p.Role+"_name FROM "+p.Role+" where email=\""+p.Email+"\" and password=\""+p.Password+"\"");

	if(er!=nil){
		fmt.Println(er);
		auth=false;
	}else{
		
		for rows.Next(){
		rows.Scan(&temp.User_id,&temp.Name);
		}
		auth=true;
		
	}
	if(temp.Name==""){
		var err Error
		err = SetError(err, "Username or Password is incorrect")
		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(err)
		return
	}
	validToken, err := GenerateJWT(temp.Name,temp.User_id,p.Role,auth);
  
	if err != nil {
	
		return
	}
	var token Token
	token.Email = p.Email;
	token.TokenString = validToken
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(token)
}



