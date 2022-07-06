import { parseISO,formatDistanceToNow } from "date-fns";

import React from 'react'

function TimeAgo({timestamp}) {
    let timeAgo=''
    if(timestamp){
        const date=parseISO(timestamp)
        const timePeriod=formatDistanceToNow(date)
        timeAgo=`${timePeriod} ago`
    }
  return (
    <span title={timestamp}>
      <i style={{marginLeft:'20px'}}>{timeAgo}</i>
    </span>
  )
}

export default TimeAgo