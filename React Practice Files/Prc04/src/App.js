import React, { useState } from 'react';
import PostsList from './features/posts/postsList';
import './App.scss';
import AddPostForm from './features/posts/AddPostForm';
function App() {
  
  return (
    <main className="App">
      <AddPostForm/>
      <PostsList/>
    </main>
  );
}

export default App;
