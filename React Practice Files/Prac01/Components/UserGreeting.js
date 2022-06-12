import React, { Component } from 'react';
class UserGreeting extends Component {
    state = { 
        isLoggedin:true
     } 
    render() { 

        return this.state.isLoggedin && <div>Welcome Faradars</div>
        
            // return(
            //     this.state.isLoggedin?
            //     <div>Welcome Faradars</div>:
            //     <div>Welcome Guest</div>
            // )


            // let message
            // if(this.state.isLoggedin){
            //     message=<div>Welcome Faradars</div>
            // }else{
            //     message=<div>Welcome Guest</div>
            // }

            //return <div>{message}</div>
            // if(this.state.isLoggedin){
            //     return <div>Welcome Faradars</div>
            // }else{
            //     return <div>Welcome Guest</div>
            // }
    }
}
 
export default UserGreeting;