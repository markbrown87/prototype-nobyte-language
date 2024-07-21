FROM ruby:3.2

RUN gem install bundler
RUN mkdir /website
COPY ../../ /website/
WORKDIR /website/
RUN bundle install
CMD ["bundle", "exec", "jekyll", "serve", "--host", "0.0.0.0"]