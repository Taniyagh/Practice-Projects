import { useSelector } from "react-redux";
import { SelectAllPosts } from "./postsSlice";
import React from 'react'
import PostAuthor from "./postAuthor";
import TimeAgo from "./TimeAgo";
import ReactionButton from "./ReactionButton";

const PostsList = () => {
    const posts=useSelector(SelectAllPosts)
    const orderedPosts=posts.slice().sort((a,b)=>b.date.localeCompare(a.date))
    const renderedPosts=orderedPosts.map(post=>(
        <article key={post.id}>
            <h3>{post.title}</h3>
            <p>{post.content.substring(0,100)}</p>
            <p className="postCredit">
              <PostAuthor userId={post.userId}/>
              <TimeAgo timestamp={post.date}/>
            </p>
            <ReactionButton post={post}/>
        </article>
    ))
  return (
    <section>
        <h2>Posts</h2>
        {renderedPosts}
    </section>
  )
}

export default PostsList