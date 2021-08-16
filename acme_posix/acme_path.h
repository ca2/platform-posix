/*****<3ThomasBorregaardSørensen!!Created by camilo*/
// From acme_posix/acme_file.h
// on 2021-08-12
// 18:18 BRT


namespace posix
{


   class CLASS_DECL_ACME acme_path :
      virtual public ::acme_path
   {
   public:


      acme_path();
      ~acme_path() override;


      bool is_file_or_dir(const char * path1, ::file::enum_type * petype) override;

      ::file::path _final(const char * path) override;


   };


} // namespace posix



