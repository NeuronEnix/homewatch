type T_Request = {
  meta: {
    path: string,
    method: "GET" | "POST"
    sourceInfo: {
      ip: string,
      port: number,
      agent: string
    }
  },
  header: { [key: string]: string }
}

type T_Response = {
  httpCode: 200 | 400,
  code: number,
  msg: string,
  data: { [key: string]: any }
}

async function handler( req: T_Request ): Promise<T_Response> {
  console.log( req );
  return {
    httpCode: 200,
    code: 100,
    msg: "OK",
    data: {}
  };
}

module.exports = { handler };
