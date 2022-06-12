import React, { Component } from 'react';
class Form extends Component {
    state = { 
        username:'',
        password:'',
        comment:'',
        type:''
     } 

    handleUsernameChange=(e)=>{
        this.setState({
            username:e.target.value
        })
    }
    handlePasswordChange=(e)=>{
        this.setState({
            password:e.target.value
        })
    }
    handleCommentChange=(e)=>{
        this.setState(
            {
                comment:e.target.value
            }
        )
    }

    handleTypeChange=(e)=>{
        this.setState(
            {
                type:e.target.value
            }
        )
    }
    handleSubmit=(e)=>{
        alert(
            [
                this.state.username,
                this.state.password,
                this.state.comment,
                this.state.type,
            ]
        )
        e.preventDefault()
    }
    render() { 
        return (
            <form onSubmit={this.handleSubmit}>
                <div>
                    <lable>Username: </lable>
                    <input type='text' value={this.state.username} 
                    onChange={this.handleUsernameChange}></input>
                </div>
                <div>
                    <lable>Password: </lable>
                    <input type='text' value={this.state.password} 
                    onChange={this.handlePasswordChange}></input>
                </div>
                <div>
                    <lable>Comments: </lable>
                    <textarea value={this.state.comment} 
                    onChange={this.handleCommentChange}></textarea>
                </div>
                <div>
                    <lable>Topics: </lable>
                    <select value={this.state.type} onChange={this.handleTypeChange}>
                        <option value='React'>React</option>
                        <option value='Angular'>Angular</option>
                        <option value='Vuejs'>Vuejs</option>
                    </select>
                </div>
                <button type='submit'>Send</button>
            </form>
            
        );
    }
}
 
export default Form;