import { createSlice } from "@reduxjs/toolkit";

const initialState=[
    {id:'0' , name:'Ali Taheri'},
    {id:'1', name:'Negin Khodadad'},
    {id:'3', name:"Saman Rajabi"},
    {id:'4', name:'Mehran Tehrani'}
]

const usersSlice=createSlice({
    name:'users',
    initialState,
    reducers:{

    }
})


export const getAllUsers=(state)=>state.users;
export default usersSlice.reducer;
