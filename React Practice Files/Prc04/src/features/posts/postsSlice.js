import { createSlice } from "@reduxjs/toolkit";
import { nanoid } from "@reduxjs/toolkit";
import { sub } from 'date-fns';

const initialState = [
    {
        id: '1',
        title: 'learning redux toolkit',
        content: "It is so cool",
        userId: '0',
        reaction: {
            thumbsUp: 0,
            wow: 0,
            heart: 0,
            rocket: 0,
            coffee: 0
        },
        date: sub(new Date(), { minutes: 10 }).toISOString()
    },
    {
        id: '2',
        title: 'Slices',
        userId: '1',
        reaction: {
            thumbsUp: 0,
            wow: 0,
            heart: 0,
            rocket: 0,
            coffee: 0
        },
        content: 'Slices make the code so clean and easy to read',
        date: sub(new Date(), { minutes: 35 }).toISOString()
    },
    {
        id: '3',
        title: 'State Manageent',
        userId: '3',
        reaction: {
            thumbsUp: 0,
            wow: 0,
            heart: 0,
            rocket: 0,
            coffee: 0
        },
        content: "State management is a key to easily handle changes and app development",
        date: sub(new Date(), { minutes: 25 }).toISOString()
    }
]

const postsSlice = createSlice({
    name: 'posts',
    initialState,
    reducers: {
        postAdded: {
            reducer(state, action) {
                state.push(action.payload)
            },
            prepare(title, content, userId, date) {
                return {
                    payload: {
                        id: nanoid(),
                        title,
                        content,
                        userId,
                        reaction: {
                            thumbsUp: 0,
                            wow: 0,
                            heart: 0,
                            rocket: 0,
                            coffee: 0
                        },
                        date: new Date().toISOString()
                    }
                }
            }
        },
        reactionAdded(state, action) {
            const { postId, reaction } = action.payload
            const existingPost = state.find(post => post.id === postId)
            if (existingPost) {
                existingPost.reaction[reaction]++
            }
        }
    }
})
export const SelectAllPosts = (state) => state.posts;
export const { postAdded,reactionAdded } = postsSlice.actions;
export default postsSlice.reducer