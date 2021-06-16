using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;
using DeepAI;

namespace DeepAICsWrapper
{
    public static class Wrapper
    {
    public static string Densecap_ProcessFile(string key, string filename) {
      DeepAI_API api = new DeepAI_API(apiKey: key);
      StandardApiResponse resp = api.callStandardApi("densecap", new
      {
        image = File.OpenRead(filename),
      });
      return api.objectAsJsonString(resp);
    }
    public static string Densecap_ProcessUrl(string key, string url) {
      DeepAI_API api = new DeepAI_API(apiKey: key);
      StandardApiResponse resp = api.callStandardApi("densecap", new
      {
        image = url,
      });
      return api.objectAsJsonString(resp);
    }

  }
}
